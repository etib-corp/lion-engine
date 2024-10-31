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
    init();
}

LE::GUI::SFMLContainer::~SFMLContainer()
{
}