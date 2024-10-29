/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** LoaderLib
*/

#include "NetworkLoaderLib.hpp"
#include "globalLogger.hpp"

NetworkLoaderLib::NetworkLoaderLib(const std::string &NetworkModule)
{
    _pathNetworkModule = NetworkModule;
    _handleNetworkModule = nullptr;
    _createNetworkModule = nullptr;
}

NetworkLoaderLib::~NetworkLoaderLib()
{
    if (_handleNetworkModule) {
        CLOSE_SYM(_handleNetworkModule);
    }
}

void NetworkLoaderLib::LoadModule(void)
{
    OPEN_SYM(_pathNetworkModule, _handleNetworkModule);
    if (_handleNetworkModule == nullptr)
        throw LoaderLibError("Can't load the module NETWORK");

    LOAD_SYM(_handleNetworkModule, _createNetworkModule, "createNetworkModule", INetworkModule*(*)());
    if (_createNetworkModule == nullptr)
        throw LoaderLibError("Can't load the symbol createNetworkModule");
}

INetworkModule *NetworkLoaderLib::createNetworkModule(void)
{
    if (_createNetworkModule == nullptr)
        throw LoaderLibError("createNetworkModule is not loaded");

    return _createNetworkModule();
}
