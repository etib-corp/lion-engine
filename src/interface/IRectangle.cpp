/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IRectangle
*/

#include "IRectangle.hpp"


LE::Vector2<float> LE::IRectangle::getSize() const
{
    return _size;
}

void LE::IRectangle::resize(float width, float height)
{
    _size.x = width;
    _size.y = height;
}