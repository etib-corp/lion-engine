#pragma once

#include <cstdint>

#include "message/Broker.hpp"

#include "ResolvingLib.hpp"
#include "interface/INetworkModule/INetworkModule.hpp"
#include "interface/INetworkModule/IServer.hpp"

namespace LE {
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
        ServerBroker(INetworkModule *network_module, std::string _listen_address, std::uint16_t listen_port);

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
        void sendToAllClient(std::shared_ptr<Message>message, std::uint8_t topic_id, std::uint8_t ecs_id);

    private:
        std::string _listen_address;
        unsigned short _listen_port;
        IServer *_server;

        void _sendMessage(std::shared_ptr<Message> message) override;

        void _onReceiveRequestCallback(const Request &request);

        void _onClientDisconnectedCallback(ISession *session);
    };

}
