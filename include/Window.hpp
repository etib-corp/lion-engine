/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Window
*/

#pragma once

#include "common.hpp"
#include "Drawable.hpp"

namespace LE {
    class Window {
        public:
            Window(int width, int height, std::string title);
            ~Window();

            void clear(const LE::Color&  color);
            void close();
            void display();
            void draw(const LE::Drawable& drawable);

        private:
            sf::RenderWindow _window;
    };
}