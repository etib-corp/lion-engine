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

    for (auto &[key, callback] : _eventCallbacks) {
        if (key->input == LE::KEYBOARD) {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(sfmlKeys[key->key]))) {
                if ((key->type == LE::JUST_PRESSED && !key->_alreadyPressed) || key->type == LE::PRESSED)
                    callback(_engine, 0);
                key->_alreadyPressed = true;
            }
            if (!sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(sfmlKeys[key->key]))) {
                if ((key->type == LE::JUST_RELEASED && key->_alreadyPressed) || key->type == LE::RELEASED)
                    callback(_engine, 0);
                key->_alreadyPressed = false;
            }
        }
        if (key->input == LE::MOUSE) {
            if (sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(sfmlKeys[key->key]))) {
                if ((key->type == LE::JUST_PRESSED && !key->_alreadyPressed) || key->type == LE::PRESSED)
                    callback(_engine, 0);
                key->_alreadyPressed = true;
            }
            if (!sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(sfmlKeys[key->key]))) {
                if ((key->type == LE::JUST_RELEASED && key->_alreadyPressed) || key->type == LE::RELEASED)
                    callback(_engine, 0);
                key->_alreadyPressed = false;
            }
        }
    }
    while (window->getWindow()->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            exit(0);
        }
    }
}
/*
    while (window->getWindow()->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            window->close();
        }
        if (_event.type == sf::Event::KeyPressed) {
            for (auto &[key, callback] : _eventCallbacks) {
                if (_event.key.code == key->key && ((key->type == LE::JUST_PRESSED && !key->_alreadyPressed) || key->type == LE::PRESSED)) {
                    callback(_engine, 0);
                    key->_alreadyPressed = true;
                }
            }
        }
        if (_event.type == sf::Event::KeyReleased) {
            for (auto &[key, callback] : _eventCallbacks) {
                if (_event.key.code == key->key && (key->type == LE::JUST_RELEASED && key->_alreadyPressed) || key->type == LE::RELEASED) {
                    callback(_engine, 0);
                    key->_alreadyPressed = false;
                }
            }
        }
    }
*/
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