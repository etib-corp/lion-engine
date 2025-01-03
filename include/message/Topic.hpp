#pragma once

#include <cstdint>
#include <string>
#include <queue>
#include <memory>
#include <mutex>

#include "message/Message.hpp"

namespace LE
{
    /**
     * @class Topic
     * @brief A class that represents a topic which holds a queue of messages.
     *
     * The Topic class is responsible for managing a queue of messages. It allows
     * adding messages to the queue and retrieving messages from the queue.
     */
    class Topic
    {
    public:
        /**
         * @brief Constructs a new Topic object.
         *
         * @param ecs_id The ID associated with the topic.
         * @param id The ID of the topic.
         */
        Topic(std::uint8_t ecs_id, std::uint8_t id);

        /**
         * @brief Destroys the Topic object.
         */
        ~Topic(void);

        /**
         * @brief Adds a message to the topic's queue.
         *
         * @param message A unique pointer to the message to be added.
         */
        void addMessage(std::shared_ptr<Message> message);
        /**
         * @brief Retrieves and removes the next message from the topic's queue.
         *
         * @return A unique pointer to the next message, or nullptr if the queue is empty.
         */
        std::shared_ptr<Message> getMessage(void);

    private:
        std::uint8_t _ecs_id;                           ///< The ID associated with the topic.
        std::uint8_t _id;                               ///< The ID of the topic.
        std::queue<std::shared_ptr<Message>> _messages; ///< The queue of messages.
        std::mutex _mutex;                              ///< The mutex used to ensure thread safety.
    };
}
