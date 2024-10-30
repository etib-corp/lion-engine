/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ICameraComponent
*/

#pragma once

#include "Maths/Vector2.hpp"
#include "Maths/Vector3.hpp"

/**
 * @brief The LE namespace.
 */
namespace LE {
    /**
     * @brief An interface for camera components.
     *
     * This interface is used to define the properties of a camera component.
     */
    class ICameraComponent {
        public:
            /**
             * @brief Destructor for the ICameraComponent object.
             */
            virtual ~ICameraComponent() = default;

            LE::Vector2<float> position;        ///< The position of the camera.
            LE::Vector2<float> size;            ///< The size of the camera.
            float rotation;                     ///< The rotation of the camera.
    };
}