#pragma once

#include "interface/ICoreModule/ICoreModule.hpp"

class ClientCoreModule : public ICoreModule
{
public:
    ClientCoreModule(void);
    ~ClientCoreModule(void);
};

ICoreModule *createCoreModule(void);