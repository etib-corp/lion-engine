#include "message/Broker.hpp"

std::unique_ptr<LE::Topic> &LE::Broker::getTopic(std::uint8_t ecs_id, std::uint8_t id)
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_topics.find(std::make_pair(ecs_id, id)) == _topics.end())
        throw std::runtime_error("Topic not found");
    return _topics[std::make_pair(ecs_id, id)];
}

void LE::Broker::removeTopic(std::uint8_t ecs_id, std::uint8_t id)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _topics.erase(std::make_pair(ecs_id, id));
}


void LE::Broker::addMessage(std::uint8_t ecs_id, std::uint8_t topic_id, std::shared_ptr<Message>message)
{
    std::lock_guard<std::mutex> lock(_mutex);

    message->setEmmiterID(_ecs_id);
    message->setReceiverID(ecs_id);
    message->setTopicID(topic_id);
    _outgoing_messages.push(message);
}

std::shared_ptr<LE::Message>LE::Broker::getMessage(std::uint8_t ecs_id, std::uint8_t topic_id)
{
    return getTopic(ecs_id, topic_id)->getMessage();
}

void LE::Broker::_networkRoutine(void)
{
    _sendMessages();
}

void LE::Broker::_logicalRoutine()
{
    std::shared_ptr<LE::Message>message = nullptr;

    while (!_incomming_messages.empty())
    {
        message = _incomming_messages.front();
        _incomming_messages.pop();
        auto key = std::make_pair(message->getEmmiterID(), message->getTopicID());
        if (_topics.find(key) == _topics.end())
            _topics[key] = std::make_unique<Topic>(message->getEmmiterID(), message->getTopicID());
        _topics[key]->addMessage(message);
        std::cout << "Message received" << std::endl;
        std::cout << *message << std::endl;
        std::cout << std::endl;
    }
}

void LE::Broker::_routine(void)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _networkRoutine();
    _logicalRoutine();
}

void LE::Broker::_run(void)
{
    _is_running = true;
    // _mutex.unlock(); // JUST FOR WINDOWS
    while (_is_running)
        _routine();
    std::cout << "Broker routine stopped" << std::endl;
}

void LE::Broker::_stop(void)
{
    std::cout << "Broker is stopping" << std::endl;
    _mutex.lock();
    _is_running = false;
    _mutex.unlock();
    std::cout << "Broker is joining thread" << std::endl;
    _thread.join();
    std::cout << "Broker thread joined" << std::endl;
}

void LE::Broker::_sendMessages(void)
{
    std::shared_ptr<Message>message = nullptr;
    while (!_outgoing_messages.empty())
    {
        message = _outgoing_messages.front();
        _outgoing_messages.pop();
        std::cout << "Message sent" << std::endl;
        std::cout << *message << std::endl;
        std::cout << std::endl;
        _sendFunction(message);
    }
}
