#include "ServerCoreModule.hpp"

ServerCoreModule::ServerCoreModule(void)
{
}

ServerCoreModule::~ServerCoreModule(void)
{
}

ICoreModule *createCoreModule(void)
{
    return new ServerCoreModule();
}