/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLRectangle
*/

#include "SFMLRectangle.hpp"

LE::SFMLRectangle::SFMLRectangle(const LE::Vector3<float>& position, const LE::Vector2<float>& size, LE::Color *color, std::shared_ptr<LE::IWindow> window)
{
    _position = position;
    _size = size;
    _color = color;
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    init();
}

LE::SFMLRectangle::~SFMLRectangle()
{
}

void LE::SFMLRectangle::init()
{
    _rectangle = new sf::RectangleShape(sf::Vector2f(_size.x, _size.y));
    _rectangle->setPosition(sf::Vector2f(_position.x, _position.y));
    _rectangle->setFillColor(sf::Color(_color->getRed(), _color->getGreen(), _color->getBlue(), _color->getAlpha()));
}

void LE::SFMLRectangle::setPosition(const LE::Vector3<float>& position)
{
    LE::IRectangle::setPosition(position);

    _rectangle->setPosition(sf::Vector2f(_position.x, _position.y));
}

void LE::SFMLRectangle::move(const LE::Vector3<float>& moveVector)
{
    LE::IRectangle::move(moveVector);

    _rectangle->move(sf::Vector2f(moveVector.x, moveVector.y));
}

void LE::SFMLRectangle::draw()
{
    _window->getWindow()->draw(*_rectangle);
}