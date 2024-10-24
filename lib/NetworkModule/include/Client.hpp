/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Client
*/

#pragma once

#include "interface/INetworkModule/IClient.hpp"
#include "dllDefine.hpp"
#include <boost/asio.hpp>
#include "message/Message.hpp"
#include <thread>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)

class LIBRARY_API Client : public IClient {
    public:
        Client(const std::string &ip, const int &port);
        ~Client();

        void connectToServer() override;

        void readTCP() override;

        void readUDP() override;

        void sendTCP(const std::string& request) override;

        void sendUDP(const std::string& request) override;

        void handShake() override;

    protected:

        boost::asio::io_context _ioContext;

        boost::asio::ip::tcp::endpoint _endpointTCPServer;
        boost::asio::ip::udp::endpoint _endpointUDPServer;

        boost::asio::ip::udp::endpoint _endpointUDPReceiver;

        boost::asio::ip::tcp::socket _socketTCP;

        boost::asio::ip::udp::socket _socketUDP;

        std::thread _thread;

    private:
};

#else

class Client : public IClient {
    public:
        Client(const std::string &ip, const int &port);
        ~Client();

        void connectToServer() override;

        void readTCP() override;

        void readUDP() override;

        void sendTCP(const std::string& request) override;

        void sendUDP(const std::string& request) override;

        void handShake() override;

    protected:

        boost::asio::io_context _ioContext;

        boost::asio::ip::tcp::endpoint _endpointTCPServer;
        boost::asio::ip::udp::endpoint _endpointUDPServer;

        boost::asio::ip::udp::endpoint _endpointUDPReceiver;

        boost::asio::ip::tcp::socket _socketTCP;

        boost::asio::ip::udp::socket _socketUDP;

        std::thread _thread;

    private:
};

#endif
