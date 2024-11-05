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
        bool isPressed = false;
        if (key.input == LE::KEYBOARD) {
            isPressed = sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(sfmlKeys[key.key]));
            if (isPressed) {
                if ((key.type == LE::JUST_PRESSED && !key._alreadyPressed) || key.type == LE::PRESSED)
                    callback.callback(_engine, 0);
            }
            if (!isPressed) {
                if ((key.type == LE::JUST_RELEASED && key._alreadyPressed) || key.type == LE::RELEASED)
                    callback.callback(_engine, 0);
            }
            key.setAlreadyPressed(isPressed);
        }
        if (key.input == LE::MOUSE) {
            isPressed = sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(sfmlKeys[key.key]));
            if (isPressed) {
                if ((key.type == LE::JUST_PRESSED && !key._alreadyPressed) || key.type == LE::PRESSED)
                    callback.callback(_engine, 0);
            }
            if (!isPressed) {
                if ((key.type == LE::JUST_RELEASED && key._alreadyPressed) || key.type == LE::RELEASED)
                    callback.callback(_engine, 0);
            }
            key.setAlreadyPressed(isPressed);
        }
        if (sf::Joystick::isConnected(0)) {
            if (key.input == LE::JOYSTICK_BUTTON) {
                isPressed = sf::Joystick::isButtonPressed(0, sfmlKeys[key.key]);
                if (isPressed) {
                    if ((key.type == LE::JUST_PRESSED && !key._alreadyPressed) || key.type == LE::PRESSED)
                        callback.callback(_engine, 0);
                }
                if (!isPressed) {
                    if ((key.type == LE::JUST_RELEASED && key._alreadyPressed) || key.type == LE::RELEASED)
                        callback.callback(_engine, 0);
                }
                key.setAlreadyPressed(isPressed);
            }
            if (key.input == LE::JOYSTICK_AXIS) {
                float value = sf::Joystick::getAxisPosition(0, static_cast<sf::Joystick::Axis>(sfmlKeys[key.key]));
                if (value > key.axisDeadzone || value < -key.axisDeadzone) {
                    callback.callbackAxis(_engine, 0, value);
                }
            }
        }
    }
    while (window->getWindow()->pollEvent(_event)) {
        if (_event.type == sf::Event::Closed) {
            exit(0);
        }
    }
}
