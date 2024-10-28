/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ISpriteComponent
*/

#pragma once

#include <string>

namespace LE {
    class ISpriteComponent {
        public:
            ISpriteComponent() = default;
            virtual ~ISpriteComponent() = default;

            std::string path;
            unsigned int width;
            unsigned int height;
            bool hidden;
            float rotation;
    };
}
