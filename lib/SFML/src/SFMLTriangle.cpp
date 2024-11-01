/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLTriangle
*/

#include "SFMLTriangle.hpp"

LE::SFMLTriangle::SFMLTriangle(const LE::Vector3<float> &point1, const LE::Vector3<float> &point2, const LE::Vector3<float> &point3, std::shared_ptr<LE::IWindow> window)
{
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _point1 = point1;
    _point2 = point2;
    _point3 = point3;
    init();
}

LE::SFMLTriangle::SFMLTriangle(const LE::Vector2<float> &point1, const LE::Vector2<float> &point2, const LE::Vector2<float> &point3, std::shared_ptr<LE::IWindow> window)
{
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _point1 = LE::Vector3<float>(point1.x, point1.y, 0);
    _point2 = LE::Vector3<float>(point2.x, point2.y, 0);
    _point3 = LE::Vector3<float>(point3.x, point3.y, 0);
    init();
}

LE::SFMLTriangle::SFMLTriangle(const LE::Vector2<float> &pos, float size, std::shared_ptr<LE::IWindow> window)
{
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _point1 = LE::Vector3<float>(pos.x, pos.y, 0);
    _point2 = LE::Vector3<float>(pos.x + size, pos.y, 0);
    _point3 = LE::Vector3<float>(pos.x + size, pos.y + size, 0);
    init();
}

LE::SFMLTriangle::~SFMLTriangle()
{
}

void LE::SFMLTriangle::init()
{
    _triangle = new sf::ConvexShape(3);
    _triangle->setPoint(0, sf::Vector2f(_point1.x, _point1.y));
    _triangle->setPoint(1, sf::Vector2f(_point2.x, _point2.y));
    _triangle->setPoint(2, sf::Vector2f(_point3.x, _point3.y));
}

void LE::SFMLTriangle::move(const LE::Vector3<float> &moveVector)
{
    LE::ITriangle::move(moveVector);
    _triangle->move(sf::Vector2f(moveVector.x, moveVector.y));
}

void LE::SFMLTriangle::draw()
{
    _window->getWindow()->draw(*_triangle);
}
