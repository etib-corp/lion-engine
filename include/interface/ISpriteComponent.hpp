/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ISpriteComponent
*/

#pragma once

#include <string>
#include "Maths/Vector4.hpp"

namespace LE
{
    /**
     * @class ISpriteComponent
     * @brief Interface for sprite components.
     *
     * The ISpriteComponent interface provides a way to create sprite components.
     */
    class ISpriteComponent
    {
    public:
        /**
         * @brief Construct a new ISpriteComponent object
         */
        virtual ~ISpriteComponent() = default;

        std::string path;    ///< The path to the sprite.
        unsigned int width;  ///< The width of the sprite.
        unsigned int height; ///< The height of the sprite.
        bool hidden;         ///< Whether the sprite is hidden.
        float rotation;      ///< The rotation of the sprite.
        LE::Vector4<int> rect = {0, 0, static_cast<int>(width), static_cast<int>(height)}; ///< The rectangle of the sprite.
    };
}
