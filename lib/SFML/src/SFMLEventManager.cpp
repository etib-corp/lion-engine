/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEventManager
*/

#include "SFMLEventManager.hpp"

LE::SFMLEventManager::SFMLEventManager(std::shared_ptr<LE::IEngine> engine)
    : _engine(engine)
{
}

LE::SFMLEventManager::~SFMLEventManager()
{
}

void LE::SFMLEventManager::pollEvents()
{
    std::shared_ptr<LE::SFMLWindow> window = _engine->getWindow<LE::SFMLWindow>();

    while (window->getWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        for (auto &[key, callback] : _eventCallbacks) {
            if (event.type == sf::Event::KeyPressed && key.type == LE::JUST_PRESSED && event.key.code == key.key && !key._alreadyPressed) {
                callback(_engine, 0);
                const_cast<LE::Key &>(key)._alreadyPressed = true;
            }
            if (event.type == sf::Event::KeyReleased && key.type == LE::JUST_RELEASED && event.key.code == key.key) {
                callback(_engine, 0);
                const_cast<LE::Key &>(key)._alreadyPressed = false;
            }
            if (event.type == sf::Event::KeyPressed && key.type == LE::PRESSED && event.key.code == key.key) {
                callback(_engine, 0);
                const_cast<LE::Key &>(key)._alreadyPressed = true;
            }
            if (event.type == sf::Event::KeyReleased && key.type == LE::RELEASED && event.key.code == key.key) {
                callback(_engine, 0);
                const_cast<LE::Key &>(key)._alreadyPressed = false;
            }
        }
    }
}
