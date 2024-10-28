#pragma once

#include <memory>

#include "CoreModule.hpp"
#include "LoaderLib.hpp"

#include "message/ServerBroker.hpp"

namespace LE
{
    class ServerCoreModule : public LE::CoreModule
    {
    public:
        ServerCoreModule(std::shared_ptr<LoaderLib> lib_loader, std::string listen_address, unsigned short listen_port);
        ~ServerCoreModule(void);

    private:
        std::shared_ptr<LoaderLib> _lib_loader;
        std::string _listen_address;
        unsigned short _listen_port;
        std::shared_ptr<LE::ServerBroker> _server_broker;
    };
} // namespace LE

