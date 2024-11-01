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

void LE::IShape::setColor(std::shared_ptr<LE::Color> color)
{
    _color->setRed(color->getRed());
    _color->setGreen(color->getGreen());
    _color->setBlue(color->getBlue());
    _color->setAlpha(color->getAlpha());
}

void LE::IShape::move(const LE::Vector3<float>& moveVector)
{
    _position += moveVector;
}

LE::Vector3<float> LE::IShape::getPosition() const
{
    return _position;
}

std::shared_ptr<LE::Color> LE::IShape::getColor() const
{
    return _color;
}
