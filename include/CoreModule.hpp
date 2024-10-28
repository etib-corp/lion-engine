#pragma once

#include "interface/INetworkModule/INetworkModule.hpp"

#include "ResponsibilityChain.hpp"

namespace LE
{
    class CoreModule
    {
    public:
        virtual ~CoreModule(void) = default;

    public:
        INetworkModule *_network_module;
        
    };

} // namespace LE