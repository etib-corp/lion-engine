/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Game
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include "message/ClientBroker.hpp"
#include "message/ServerBroker.hpp"
#include "ResponsibilityChain.hpp"
#include "SceneManager.hpp"

namespace LE
{
    class IEngine;
    class IGame
    {
    public:
        virtual ~IGame() = default;

        virtual void init(LE::IEngine &) = 0;

        virtual void update() = 0;

        std::shared_ptr<ClientBroker> &getClientBroker() { return _clientBroker; }

        std::shared_ptr<ServerBroker> &getServerBroker() { return _serverBroker; }

        std::shared_ptr<ResponsibilityChain> &getResponsibilityChain() { return _responsibilityChain; }

        std::shared_ptr<SceneManager> &getSceneManager() { return _sceneManager; }

        void setClientBroker(std::shared_ptr<ClientBroker> clientBroker) { _clientBroker = clientBroker; }

    protected:
        std::shared_ptr<ClientBroker> _clientBroker;
        std::shared_ptr<ServerBroker> _serverBroker;
        std::shared_ptr<ResponsibilityChain> _responsibilityChain;
        std::shared_ptr<SceneManager> _sceneManager;

    private:
    };
}

#endif /* !IGAME_HPP_ */
