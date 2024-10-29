#pragma once

#include "interface/INetworkModule/INetworkModule.hpp"

#include "ResponsibilityChain.hpp"

namespace LE
{
    class CoreModule
    {
    public:
        virtual ~CoreModule(void) = default;

    protected:
        INetworkModule *_network_module;
        std::unique_ptr<ResponsibilityChain> _responsibility_chain;

        void _createResponsibilityChain(void)
        {
            _responsibility_chain = std::make_unique<ResponsibilityChain>();
        }
    };

} // namespace LE