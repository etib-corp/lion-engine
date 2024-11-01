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

std::vector<LE::Vector3<float>> getRightestsPoints(const LE::Vector3<float>& point1, const LE::Vector3<float>& point2, const LE::Vector3<float>& point3)
{
    std::vector<LE::Vector3<float>> points;

    if (point1.x > point2.x && point1.x > point3.x)
        points.push_back(point1);
    if (point2.x > point1.x && point2.x > point3.x)
        points.push_back(point2);
    if (point3.x > point1.x && point3.x > point2.x)
        points.push_back(point3);
    return points;
}

std::vector<LE::Vector3<float>> getLowestsPoints(const LE::Vector3<float>& point1, const LE::Vector3<float>& point2, const LE::Vector3<float>& point3)
{
    std::vector<LE::Vector3<float>> points;

    if (point1.y > point2.y && point1.y > point3.y)
        points.push_back(point1);
    if (point2.y > point1.y && point2.y > point3.y)
        points.push_back(point2);
    if (point3.y > point1.y && point3.y > point2.y)
        points.push_back(point3);
    return points;
}

LE::Vector3<float> getLeftestPoint(const LE::Vector3<float>& point1, const LE::Vector3<float>& point2, const LE::Vector3<float>& point3)
{
    if (point1.x < point2.x && point1.x < point3.x)
        return point1;
    if (point2.x < point1.x && point2.x < point3.x)
        return point2;
    if (point3.x < point1.x && point3.x < point2.x)
        return point3;
    return point1;
}

LE::Vector3<float> getHighestPoint(const LE::Vector3<float>& point1, const LE::Vector3<float>& point2, const LE::Vector3<float>& point3)
{
    if (point1.y < point2.y && point1.y < point3.y)
        return point1;
    if (point2.y < point1.y && point2.y < point3.y)
        return point2;
    if (point3.y < point1.y && point3.y < point2.y)
        return point3;
    return point1;
}

void LE::ITriangle::resize(float width, float height)
{
    auto rightestsPoints = getRightestsPoints(_point1, _point2, _point3);
    auto lowestsPoints = getLowestsPoints(_point1, _point2, _point3);
    auto leftestPoint = getLeftestPoint(_point1, _point2, _point3);
    auto highestPoint = getHighestPoint(_point1, _point2, _point3);

    if (rightestsPoints.size() != 3 && rightestsPoints.size() != 0) {
        for (auto &point : rightestsPoints) {
            _point1 += _point1 == point ? LE::Vector3<float>{leftestPoint.x - width, 0, 0} : LE::Vector3<float>{0, 0, 0};
            _point2 += _point2 == point ? LE::Vector3<float>{leftestPoint.x - width, 0, 0} : LE::Vector3<float>{0, 0, 0};
            _point3 += _point3 == point ? LE::Vector3<float>{leftestPoint.x - width, 0, 0} : LE::Vector3<float>{0, 0, 0};
        }
    }
    if (lowestsPoints.size() != 3 && lowestsPoints.size() != 0) {
        for (auto &point : lowestsPoints) {
            _point1 += _point1 == point ? LE::Vector3<float>{0, highestPoint.y - height, 0} : LE::Vector3<float>{0, 0, 0};
            _point2 += _point2 == point ? LE::Vector3<float>{0, highestPoint.y - height, 0} : LE::Vector3<float>{0, 0, 0};
            _point3 += _point3 == point ? LE::Vector3<float>{0, highestPoint.y - height, 0} : LE::Vector3<float>{0, 0, 0};
        }
    }

}

