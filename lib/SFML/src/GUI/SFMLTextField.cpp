/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** \
*/

#include "GUI/SFMLTextField.hpp"

LE::GUI::SFMLTextField::SFMLTextField(const LE::Vector3<float> &pos, std::shared_ptr<LE::IWindow> window, const std::string &label, const std::string &placeholder)
{
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _label = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(pos.x, pos.y, 0), window, label);
    _input = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(pos.x, pos.y + 20, 0), window, placeholder);
    _isFocus = false;
    _maxChar = 18;
    _x = pos.x;
    _y = pos.y;
    init();
    addChildren(_label);
    addChildren(_input);
}

LE::GUI::SFMLTextField::~SFMLTextField()
{
}

bool LE::GUI::SFMLTextField::isHover()
{
    auto mousePos = sf::Mouse::getPosition(*_window->getWindow());
    auto windowPos = _window->getWindow()->getPosition();
    auto windowSize = _window->getWindow()->getSize();

    if (mousePos.x >= windowPos.x + _x && mousePos.x <= windowPos.x + _x + _width &&
        mousePos.y >= windowPos.y + _y && mousePos.y <= windowPos.y + _y + _height) {
        return true;
    }
    return false;
}

bool LE::GUI::SFMLTextField::isClicked()
{
    if (isHover() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return true;
    }
    return false;
}

void LE::GUI::SFMLTextField::draw()
{
    LE::GUI::IInteractable::update();
    LE::GUI::IContainer::draw();
}

void LE::GUI::SFMLTextField::init()
{
    LE::Vector3<float> pos = {_x, _y, 0};
    LE::Vector2<float> size = {_width, _height};
    _background = std::make_shared<LE::SFMLRectangle>(pos, size, std::make_shared<LE::Color>(255, 255, 255, 255), _window);
    LE::GUI::IContainer::init();
}