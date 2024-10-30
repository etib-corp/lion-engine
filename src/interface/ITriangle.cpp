/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ITriangle
*/

#include "ITriangle.hpp"

void LE::ITriangle::setPoint1(const LE::Vector3<float>& point1)
{
    _point1 = point1;
    _position.x = _point1.x + _point2.x + _point3.x / 3;
    _position.y = _point1.y + _point2.y + _point3.y / 3;
    _position.z = _point1.z + _point2.z + _point3.z / 3;
}

void LE::ITriangle::setPoint2(const LE::Vector3<float>& point2)
{
    _point2 = point2;
    _position.x = _point1.x + _point2.x + _point3.x / 3;
    _position.y = _point1.y + _point2.y + _point3.y / 3;
    _position.z = _point1.z + _point2.z + _point3.z / 3;
}

void LE::ITriangle::setPoint3(const LE::Vector3<float>& point3)
{
    _point3 = point3;
    _position.x = _point1.x + _point2.x + _point3.x / 3;
    _position.y = _point1.y + _point2.y + _point3.y / 3;
    _position.z = _point1.z + _point2.z + _point3.z / 3;
}

void LE::ITriangle::move(const LE::Vector3<float>& moveVector)
{
    _point1 += moveVector;
    _point2 += moveVector;
    _point3 += moveVector;
    _position += moveVector;
}

LE::Vector3<float> LE::ITriangle::getPoint1() const
{
    return _point1;
}

LE::Vector3<float> LE::ITriangle::getPoint2() const
{
    return _point2;
}

LE::Vector3<float> LE::ITriangle::getPoint3() const
{
    return _point3;
}
