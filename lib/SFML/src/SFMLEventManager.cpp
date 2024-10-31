/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEventManager
*/

#include "SFMLEventManager.hpp"
#include "SFMLEngine.hpp"

LE::SFMLEventManager::SFMLEventManager(LE::IEngine &engine)
    : _engine(engine)
{
}

LE::SFMLEventManager::~SFMLEventManager()
{
}

void LE::SFMLEventManager::pollEvents()
{
    std::shared_ptr<LE::SFMLWindow> window = _engine.getWindow<LE::SFMLWindow>();

    while (window->getWindow()->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            window->close();
        }
        for (auto &[key, callback] : _eventCallbacks) {
            if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == key->key && key->type == LE::JUST_PRESSED && !key->_alreadyPressed) {
                    std::cout << "Key justpPressed" << std::endl;
                    callback(_engine, 0);
                    key->_alreadyPressed = true;
                }
                if (_event.key.code == key->key && key->type == LE::PRESSED) {
                    std::cout << "Key pressed" << std::endl;
                    callback(_engine, 0);
                    key->_alreadyPressed = true;
                }
            }
            if (_event.type == sf::Event::KeyReleased) {
                if (_event.key.code == key->key && key->type == LE::JUST_RELEASED && key->_alreadyPressed) {
                    std::cout << "Key just released" << std::endl;
                    callback(_engine, 0);
                    key->_alreadyPressed = false;
                }
                if (_event.key.code == key->key && key->type == LE::RELEASED) {
                    std::cout << "Key released" << std::endl;
                    callback(_engine, 0);
                    key->_alreadyPressed = false;
                }
            }
        }
    }
}

/*
if (_event.type == sf::Event::KeyPressed && key->type == LE::JUST_PRESSED && _event.key.code == key->key && !key->_alreadyPressed) {
    callback(_engine, 0);
    const_cast<LE::Key &>(*key)._alreadyPressed = true;
}
if (_event.type == sf::Event::KeyReleased && key->type == LE::JUST_RELEASED && _event.key.code == key->key) {
    callback(_engine, 0);
    const_cast<LE::Key &>(*key)._alreadyPressed = false;
}
if (_event.type == sf::Event::KeyPressed && key->type == LE::PRESSED && _event.key.code == key->key) {
    callback(_engine, 0);
    const_cast<LE::Key &>(*key)._alreadyPressed = true;
}
if (_event.type == sf::Event::KeyReleased && key->type == LE::RELEASED && _event.key.code == key->key) {
    callback(_engine, 0);
    const_cast<LE::Key &>(*key)._alreadyPressed = false;
}
*/