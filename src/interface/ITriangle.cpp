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
}

void LE::ITriangle::setPoint2(const LE::Vector3<float>& point2)
{
    _point2 = point2;
}

void LE::ITriangle::setPoint3(const LE::Vector3<float>& point3)
{
    _point3 = point3;
}

void LE::ITriangle::move(const LE::Vector3<float>& moveVector)
{
    _point1 += moveVector;
    _point2 += moveVector;
    _point3 += moveVector;
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
