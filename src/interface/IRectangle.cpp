/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IRectangle
*/

#include "IRectangle.hpp"

void LE::IRectangle::setSize(const LE::Vector2<float>& size)
{
    _size = size;
}

LE::Vector2<float> LE::IRectangle::getSize() const
{
    return _size;
}
