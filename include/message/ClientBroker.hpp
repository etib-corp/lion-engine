#pragma once

#include <cstdint>
#include <string>

#include "message/Broker.hpp"

#include "ResolvingLib.hpp"

#include "interface/INetworkModule/INetworkModule.hpp"
#include "interface/INetworkModule/IServer.hpp"

namespace LE
{
    /**
     * @class ClientBroker
     * @brief A class that handles client-side network communication.
     *
     * ClientBroker is responsible for connecting to a server and managing the network routine
     * for client-side operations. It inherits from the Broker class.
     */
    class ClientBroker : public Broker
    {
    public:
        /**
         * @brief Constructs a new ClientBroker object.
         *
         * @param network_module The network module to use for communication.
         * @param connect_address The address to connect to.
         * @param connect_port The port to connect to.
         */
        ClientBroker(INetworkModule *network_module, std::string connect_address, std::uint16_t connect_port);

        /**
         * @brief Destroys the ClientBroker object.
         */

        ~ClientBroker(void);

        /**
         * @brief Get a message from a topic. From every ECS.
         */
        std::shared_ptr<Message> getMessageFromTopic(std::uint8_t topic_id);

    private:
        std::string _connect_address; ///< The address to connect to.
        std::uint16_t _connect_port;  ///< The port to connect to.
        IClient *_client;             ///< The client object.

        /**
         * @brief Sends a message.
         * @param message The message to send.
         */
        void _sendMessage(std::shared_ptr<Message> message) override;

        /**
         * @brief Receives a message.
         * @return The message received.
         */
        void _onReceiveRequestCallback(const Request &request);
    };
}
