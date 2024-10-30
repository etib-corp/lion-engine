/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** Transform
*/

#pragma once

#include "Maths/Vector3.hpp"
#include "Maths/Vector2.hpp"

struct TransformComponent
{
    LE::Vector3<float> position; ///< The position of the entity
    LE::Vector3<float> rotation; ///< The rotation of the entity
    LE::Vector3<float> scale;    ///< The scale of the entity
};

/**
 * @brief Create a transform component
 *
 * @param position The position of the entity
 * @param rotation The rotation of the entity
 * @param scale The scale of the entity
 * @return TransformComponent The transform component
 */

TransformComponent createTransformComponent(LE::Vector3<float> position, LE::Vector3<float> rotation, LE::Vector3<float> scale);

/**
 * @brief Outputs the transform to the output stream.
 *
 * @param os The output stream.
 * @param transform The transform to output.
 * @return The output stream.
 */
std::ostream &operator<<(std::ostream &os, const TransformComponent &transform);
