/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** Transform
*/

#pragma once

#include "Maths/Vector3.hpp"
#include "Maths/Vector2.hpp"


struct TransformComponent {
    LE::Vector3<float> position;
    LE::Vector3<float> rotation;
    LE::Vector3<float> scale;
};


TransformComponent createTransformComponent(LE::Vector3<float> position, LE::Vector3<float> rotation, LE::Vector3<float> scale);
std::ostream &operator<<(std::ostream &os, const TransformComponent &transform);
