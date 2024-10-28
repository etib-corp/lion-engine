/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEventManager
*/

#include "SFMLEventManager.hpp"

LE::SFMLEventManager::SFMLEventManager(std::shared_ptr<LE::SFMLWindow> window)
    : _window(window)
{
}

LE::SFMLEventManager::~SFMLEventManager()
{
}

void LE::SFMLEventManager::pollEvents()
{
    while (_window->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window->close();
        }
        for (auto &callback : _eventCallbacks) {
            if (event.type == sf::Event::KeyPressed && event.key.code == callback.first->key) {
                callback.second(nullptr, 0);
            }
        }
    }
}
