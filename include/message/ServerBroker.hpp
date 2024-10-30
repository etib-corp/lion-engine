#pragma once

#include <cstdint>

#include "message/Broker.hpp"

#include "ResolvingLib.hpp"
#include "interface/INetworkModule/INetworkModule.hpp"
#include "interface/INetworkModule/IServer.hpp"

namespace LE
{
    /**
     * @class ServerBroker
     * @brief A class that extends Broker to manage server-side network communication.
     *
     * The ServerBroker class is responsible for handling network operations on the server side.
     * It listens on a specified port and manages network routines.
     */
    class ServerBroker : public Broker
    {
    public:
        /**
         * @brief Constructs a new ServerBroker object.
         *
         * @param network_module The network module to use for communication.
         * @param ecs_id The ID of the ECS (Entity Component System).
         * @param listen_port The port on which the server will listen for incoming connections.
         */
        ServerBroker(INetworkModule *network_module, std::uint8_t ecs_id, std::uint16_t listen_port);

        /**
         * @brief Destroys the ServerBroker object.
         */
        ~ServerBroker(void);

        /**
         * @brief Get all clients id connected to the server.
         *
         * @return The list of clients id.
         */
        [[nodiscard]] std::vector<std::shared_ptr<ISession>> getClientsSessions(void) const { return _server->_sessionsManager->getClients(); }

        /**
         * @brief Send a message to all clients connected to the server.
         *
         * @param message The message to send.
         */
        void sendToAllClient(std::shared_ptr<Message> message, std::uint8_t topic_id, std::uint8_t ecs_id);

    private:
        std::uint16_t _listen_port; ///< The port on which the server will listen for incoming connections.
        IServer *_server;           ///< The server object.

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

        /**
         * @brief Callback for when a client connects to the server.
         * @param session The session of the client that connected.
         */
        void _onClientDisconnectedCallback(ISession *session);
    };

}
