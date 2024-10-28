#include "ClientCoreModule.hpp"

ClientCoreModule::ClientCoreModule(void)
{
}

ClientCoreModule::~ClientCoreModule(void)
{
}

ICoreModule *createCoreModule(void)
{
    return new ClientCoreModule();
}