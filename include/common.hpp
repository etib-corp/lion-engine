/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** common
*/

#pragma once

// SFML includes
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

// C++ includes
#include <iostream>

// Lion Engine includes
#include "Maths/Vector.hpp"

// Typedefs

typedef int Entity;

namespace LE {
    class Color : public sf::Color {
        public:
            Color(int r, int g, int b, int a = 255) : sf::Color(r, g, b, a) {}
            Color() : sf::Color() {}
    };
}
