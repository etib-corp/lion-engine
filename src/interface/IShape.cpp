/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IShape
*/

#include "IShape.hpp"

void LE::IShape::setPosition(const LE::Vector3<float>& position)
{
    _position = position;
}

void LE::IShape::setColor(LE::IColor *color)
{
    _color = color;
}

void LE::IShape::move(const LE::Vector3<float>& moveVector)
{
    _position += moveVector;
}

LE::Vector3<float> LE::IShape::getPosition() const
{
    return _position;
}

LE::IColor *LE::IShape::getColor() const
{
    return _color;
}
