#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <memory>
#include <thread>
#include <mutex>
#include <queue>

#include "message/Topic.hpp"

#include "interface/INetworkModule/INetworkModule.hpp"

namespace LE
{
    /**
     * @class Broker
     * @brief Manages topics and messages in a multi-threaded environment.
     *
     * The Broker class is responsible for managing topics and messages. It provides methods to add, retrieve, and
     * remove topics, as well as to add and retrieve messages. It ensures thread safety using mutex locks.
     */
    class Broker
    {
    public:
        /**
         * @brief constructor for the Broker class.
         */
        Broker(void) = default;

        /**
         * @brief Destructor for the Broker class.
         */
        ~Broker(void) = default;

        /**
         * @brief Gets the ECS ID of the broker.
         * @return The ECS ID.
         */
        int getECSId(void) const { return _ecs_id; }

        /**
         * @brief Retrieves a topic from the broker.
         * @param ecs_id The ECS ID associated with the topic.
         * @param name The name of the topic.
         * @return A unique pointer to the topic.
         * @throws std::runtime_error if the topic is not found.
         */
        std::unique_ptr<Topic> &getTopic(std::uint8_t ecs_id, std::uint8_t id);

        /**
         * @brief Removes a topic from the broker.
         * @param ecs_id The ECS ID associated with the topic.
         * @param name The name of the topic.
         */
        void removeTopic(std::uint8_t ecs_id, std::uint8_t id);

        /**
         * @brief Adds a message to a topic.
         * @param ecs_id The ECS ID associated with the topic.
         * @param topic_name The name of the topic.
         * @param message A unique pointer to the message.
         */
        void addMessage(std::uint8_t ecs_id, std::uint8_t topic_id, std::shared_ptr<Message> message);

        /**
         * @brief Retrieves a message from a topic.
         * @param ecs_id The ECS ID associated with the topic.
         * @param topic_name The name of the topic.
         * @return A unique pointer to the message.
         */
        std::shared_ptr<Message> getMessage(std::uint8_t ecs_id, std::uint8_t topic_id);

    protected:
        std::uint8_t _ecs_id;                                                            ///< The ECS ID of the broker.
        INetworkModule *_network_module;                                                 ///< The network module.
        std::map<std::pair<std::uint8_t, std::uint8_t>, std::unique_ptr<Topic>> _topics; ///< The topics managed by the broker.
        std::thread _thread;                                                             ///< The thread used to run the broker.
        std::mutex _mutex;                                                               ///< The mutex used to ensure thread safety.
        bool _is_running = true;                                                         ///< Whether the broker is running.
        std::queue<std::shared_ptr<Message>> _outgoing_messages;                         ///< The queue of outgoing messages.
        std::queue<std::shared_ptr<Message>> _incomming_messages;                        ///< The queue of incoming messages.
        std::function<void(std::shared_ptr<Message>)> _sendFunction;                     ///< The function used to send a message.

        /**
         * @brief Sets the network module.
         * @param network_module The network module.
         */
        void _setNetworkModule(INetworkModule *network_module) { _network_module = network_module; }

        /**
         * @brief Sets the ECS ID.
         * @param ecs_id The ECS ID.
         */
        void _setECSId(int ecs_id) { _ecs_id = ecs_id; }

        /**
         * @brief Sets the send function.
         * @param sendFunction The send function.
         */
        void _setSendFunction(std::function<void(std::shared_ptr<Message>)> sendFunction) { _sendFunction = sendFunction; }

        /**
         * @brief The main routine of the broker.
         */
        void _networkRoutine(void);

        /**
         * @brief The logical routine of the broker.
         */
        void _logicalRoutine(void);

        /**
         * @brief The physical routine of the broker.
         */
        void _routine(void);

        /**
         * @brief Runs the broker.
         */
        void _run(void);

        /**
         * @brief Stops the broker.
         */
        void _stop(void);

        /**
         * @brief Sends a message.
         * @param message The message to send.
         */
        virtual void _sendMessage(std::shared_ptr<Message> message) = 0;

        /**
         * @brief Receives a message.
         * @return The message received.
         */
        void _sendMessages(void);
    };
} // namespace LE
