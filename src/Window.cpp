/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Window
*/

#include "Window.hpp"

LE::Window::Window(int width, int height, std::string title)
{
    this->_window.create(sf::VideoMode(width, height), title);
}

LE::Window::~Window()
{
    this->_window.close();
}

void LE::Window::clear(const LE::Color& color)
{
    this->_window.clear(color);
}

void LE::Window::close()
{
    this->_window.close();
}

void LE::Window::display()
{
    this->_window.display();
}

void LE::Window::draw(const LE::Drawable& drawable)
{
    drawable.draw(*this);
}