#pragma once

#include "interface/ICoreModule/ICoreModule.hpp"
#include "message/Message.hpp"

class ServerCoreModule : public ICoreModule
{
public:
    ServerCoreModule(void);
    ~ServerCoreModule(void);
};

ICoreModule *createCoreModule(void);