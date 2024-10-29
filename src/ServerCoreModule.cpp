#include "ServerCoreModule.hpp"

LE::ServerCoreModule::ServerCoreModule(std::shared_ptr<LoaderLib> lib_loader, std::string listen_address, unsigned short listen_port) : _lib_loader(lib_loader), _listen_address(listen_address), _listen_port(listen_port)
{
    _network_module = _lib_loader->createNetworkModule();
    _server_broker = std::make_shared<LE::ServerBroker>(_network_module, _listen_address, _listen_port);
    _createResponsibilityChain();
}

LE::ServerCoreModule::~ServerCoreModule(void)
{
}
