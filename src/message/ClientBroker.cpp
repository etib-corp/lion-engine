/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ClientBroker
*/

#include <iostream>
#include "message/ClientBroker.hpp"
#include "globalLogger.hpp"

LE::ClientBroker::ClientBroker(INetworkModule *network_module, std::string connect_address, std::uint16_t connect_port) : _connect_address(connect_address), _connect_port(connect_port)
{
    _setNetworkModule(network_module);
    _setSendFunction(std::bind(&LE::ClientBroker::_sendMessage, this, std::placeholders::_1));

    _client = _network_module->createClient(_connect_address, _connect_port);
    std::cout << "ClientBroker network client created" << std::endl;

    _client->connectToServer();
    std::cout << "ClientBroker network client connected" << std::endl;

    _setECSId(_client->getId());

    _client->setOnReceive(std::bind(&LE::ClientBroker::_onReceiveRequestCallback, this, std::placeholders::_1));

    std::cout << "ClientBroker thread started" << std::endl;
    _thread = std::thread(&LE::ClientBroker::_run, this);
}

LE::ClientBroker::~ClientBroker(void)
{
    std::cout << "ClientBroker is stopping" << std::endl;
    _stop();
    std::cout << "ClientBroker stopped" << std::endl;
}

void LE::ClientBroker::_sendMessage(std::shared_ptr<Message>message)
{
    std::string compressed_request = message->serialize();

    if (message->isReliable())
        _client->sendTCP(compressed_request);
    else
        _client->sendUDP(compressed_request);
}

void LE::ClientBroker::_onReceiveRequestCallback(const Request &request)
{
    std::shared_ptr<Message> message = std::shared_ptr<Message>();

    message->setRequest(request);
    _incomming_messages.push(message);
}

std::shared_ptr<LE::Message> LE::ClientBroker::getMessageFromTopic(std::uint8_t topic_id)
{
    std::shared_ptr<LE::Message> message = nullptr;

    std::lock_guard<std::mutex> lock(_mutex);
    for (auto &topic : _topics) {
        if (topic.first.second != topic_id)
            continue;
        message = topic.second->getMessage();
        if (!message)
            continue;
        return message;
    }
    return nullptr;
}
