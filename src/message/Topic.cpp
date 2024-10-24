#include "message/Topic.hpp"

LE::Topic::Topic(std::uint8_t ecs_id, std::uint8_t id)
    : _ecs_id(ecs_id), _id(id)
{
}

LE::Topic::~Topic(void)
{
}

void LE::Topic::addMessage(std::shared_ptr<Message>message)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _messages.push(message);
}

std::shared_ptr<LE::Message>LE::Topic::getMessage(void)
{
    std::shared_ptr<Message>message = nullptr;
    std::lock_guard<std::mutex> lock(_mutex);
    if (_messages.empty()) {
        return nullptr;
    }
    message = _messages.front();
    _messages.pop();
    return message;
}
