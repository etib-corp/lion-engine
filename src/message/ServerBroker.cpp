#include <iostream>

#include "message/ServerBroker.hpp"
#include "Utils.hpp"
#include "globalLogger.hpp"

LE::ServerBroker::ServerBroker(INetworkModule *network_module, std::uint8_t ecs_id, std::uint16_t listen_port) : _listen_port(listen_port)
{
    _setNetworkModule(network_module);
    _setECSId(ecs_id);
    _setSendFunction(std::bind(&LE::ServerBroker::_sendMessage, this, std::placeholders::_1));

    _server = _network_module->createServer(_listen_port);
    rtypeLog->log("{}", "ServerBroker network server created");


    _server->_sessionsManager->setOnReceive(std::bind(&LE::ServerBroker::_onReceiveRequestCallback, this, std::placeholders::_1));

    _server->setOnReceiveUDP(std::bind(&LE::ServerBroker::_onReceiveRequestCallback, this, std::placeholders::_1));

    _server->run();
    rtypeLog->log("{}", "ServerBroker is running");


    rtypeLog->log("{}", "ServerBroker thread started");

    _thread = std::thread(&LE::ServerBroker::_run, this);
}

LE::ServerBroker::~ServerBroker(void)
{
    rtypeLog->log("{}", "ServerBroker is stopping");
    _stop();
    rtypeLog->log("{}", "ServerBroker stopped");
}

void LE::ServerBroker::_sendMessage(std::shared_ptr<Message>message)
{
    std::string compressed_request = message->serialize();
    auto client = _server->_sessionsManager->getClientById(message->getReceiverID());

    if (message->isReliable())
        client->sendTCP(compressed_request);
    else
        client->sendUDP(compressed_request);

}

void LE::ServerBroker::_onReceiveRequestCallback(const Request &request)
{
    std::shared_ptr<Message>message = std::make_shared<Message>();

    message->setRequest(request);
    _incomming_messages.push(message);
}

void LE::ServerBroker::_onClientDisconnectedCallback(ISession *session)
{
    std::cout << session->getId() << " disconnect" << std::endl;
    rtypeLog->log("{} disconnect", session->getId());
}

void LE::ServerBroker::sendToAllClient(std::shared_ptr<Message>message, std::uint8_t topic_id, std::uint8_t ecs_id)
{
    std::lock_guard<std::mutex> lock(_mutex);

    std::shared_ptr<Message>new_message = nullptr;
    std::vector<std::shared_ptr<ISession>> sessions = _server->_sessionsManager->getClients();

    for (auto &session : sessions)
    {
        new_message = std::make_shared<Message>();
        new_message->setRequest(message->getRequest());
        new_message->setReceiverID(session->getId());
        new_message->setEmmiterID(ecs_id);
        new_message->setTopicID(topic_id);
        _outgoing_messages.push(new_message);
    }
}
