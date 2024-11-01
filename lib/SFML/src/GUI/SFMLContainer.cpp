/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLContainer
*/

#include "GUI/SFMLContainer.hpp"

LE::GUI::SFMLContainer::SFMLContainer(LE::Vector3<float> position, LE::Vector2<float> size, std::shared_ptr<LE::IWindow> window)
{
    _x = position.x;
    _y = position.y;
    _width = size.x;
    _height = size.y;
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _background = std::make_shared<LE::SFMLRectangle>(LE::Vector3<float>(_x, _y, 0), LE::Vector2<float>(_width, _height), std::make_shared<LE::Color>(255, 255, 255, 255), window);
}

LE::GUI::SFMLContainer::~SFMLContainer()
{
}