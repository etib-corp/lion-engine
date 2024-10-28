/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IRectangle
*/

#include "IRectangle.hpp"

void LE::IRectangle::setPosition(const LE::Vector3<float>& position)
{
    _position = position;
}

void LE::IRectangle::setSize(const LE::Vector2<float>& size)
{
    _size = size;
}

void LE::IRectangle::setColor(LE::IColor *color)
{
    _color = color;
}

void LE::IRectangle::move(const LE::Vector3<float>& moveVector)
{
    _position += moveVector;
}

LE::Vector3<float> LE::IRectangle::getPosition() const
{
    return _position;
}

LE::Vector2<float> LE::IRectangle::getSize() const
{
    return _size;
}

LE::IColor *LE::IRectangle::getColor() const
{
    return _color;
}
