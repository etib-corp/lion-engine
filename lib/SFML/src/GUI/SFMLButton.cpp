/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLButton
*/

#include "GUI/SFMLButton.hpp"

LE::GUI::SFMLButton::SFMLButton(const LE::Vector3<float> &pos, const LE::Vector2<float> &size, const std::string &content)
{
    _width = size.x;
    _height = size.y;
    _x = pos.x;
    _y = pos.y;

    auto text = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(_x, _y, 0), content);

    addChildren(text);
}

LE::GUI::SFMLButton::~SFMLButton()
{
}

void LE::GUI::SFMLButton::init()
{
    LE::Vector3<float> pos = {_x, _y, 0};
    LE::Vector2<float> size = {_width, _height};
    _background = new SFMLRectangle(pos, size, new LE::Color(255, 255, 255, 255));
    LE::GUI::IContainer::init();
}
