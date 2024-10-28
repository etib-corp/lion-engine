#include "ClientCoreModule.hpp"

LE::ClientCoreModule::ClientCoreModule(std::shared_ptr<LoaderLib> lib_loader, std::string connect_address, unsigned short connect_port)
    : _lib_loader(lib_loader), _connect_address(connect_address), _connect_port(connect_port)
{
    _network_module = _lib_loader->createNetworkModule();
    _client_broker = std::make_shared<LE::ClientBroker>(_network_module, _connect_address, _connect_port);
}

LE::ClientCoreModule::~ClientCoreModule(void)
{
    delete _network_module;
}
