#pragma once

#include <string>
#include <memory>

#include "CoreModule.hpp"
#include "LoaderLib.hpp"

#include "message/ClientBroker.hpp"

namespace LE
{
    class ClientCoreModule : public LE::CoreModule
    {
    public:
        ClientCoreModule(std::shared_ptr<LoaderLib> lib_loader, std::string connect_address, unsigned short connect_port);
        ~ClientCoreModule(void);

    private:
        std::shared_ptr<LoaderLib> _lib_loader; 
        std::string _connect_address;
        unsigned short _connect_port;
        std::shared_ptr<LE::ClientBroker> _client_broker;
    };
} // namespace LE
