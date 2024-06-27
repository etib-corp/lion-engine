/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Drawable
*/

#pragma once

#include "common.hpp"

namespace LE {
    class Window;
    class Drawable {
        public:
            virtual ~Drawable() = default;
            virtual void draw(const LE::Window& window) const = 0;
    };
}