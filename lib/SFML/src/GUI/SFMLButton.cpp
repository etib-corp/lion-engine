/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLButton
*/

#include "GUI/SFMLButton.hpp"

LE::GUI::SFMLButton::SFMLButton(const LE::Vector3<float> &pos, const LE::Vector2<float> &size, const std::string &content, std::shared_ptr<LE::IWindow> window)
{
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _width = size.x;
    _height = size.y;
    _x = pos.x;
    _y = pos.y;

    _text = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(_x, _y, 0), window, content);

    addChildren(_text);
}

LE::GUI::SFMLButton::~SFMLButton()
{
}

void LE::GUI::SFMLButton::init()
{
    LE::Vector3<float> pos = {_x, _y, 0};
    LE::Vector2<float> size = {_width, _height};
    _background = std::make_shared<SFMLRectangle>(pos, size, std::make_shared<LE::Color>(255, 0, 255, 255), _window);
    LE::GUI::IContainer::init();
}

bool LE::GUI::SFMLButton::isHover()
{
    auto mousePos = sf::Mouse::getPosition(*_window->getWindow());
    auto windowPos = _window->getWindow()->getPosition();
    auto windowSize = _window->getWindow()->getSize();

    if (mousePos.x >= _x && mousePos.x <= _x + _width &&
        mousePos.y >= _y && mousePos.y <= _y + _height) {
        return true;
    }
    return false;
}

bool LE::GUI::SFMLButton::isClicked()
{
    if (isHover() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        return true;
    }
    return false;
}

void LE::GUI::SFMLButton::draw()
{
    LE::GUI::IInteractable::update();
    LE::GUI::IContainer::draw();
}