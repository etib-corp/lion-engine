/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IComponent
*/

#include "GUI/IComponent.hpp"

size_t LE::GUI::IComponent::getId() const
{
    return _id;
}

void LE::GUI::IComponent::setPos(float x, float y)
{
    _x = x;
    _y = y;
}

float LE::GUI::IComponent::getWidth() const
{
    return _width;
}

float LE::GUI::IComponent::getHeight() const
{
    return _height;
}

float LE::GUI::IComponent::getX() const
{
    return _x;
}

float LE::GUI::IComponent::getY() const
{
    return _y;
}
