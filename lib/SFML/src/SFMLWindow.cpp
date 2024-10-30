/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLWindow
*/

#include "SFMLWindow.hpp"

LE::SFMLWindow::SFMLWindow(int width, int height, const std::string& title)
{
    _width = width;
    _height = height;
    _title = title;

    _window = std::make_shared<sf::RenderWindow>();
    _window->create(sf::VideoMode(_width, _height), _title, sf::Style::Close | sf::Style::Titlebar);
}

LE::SFMLWindow::~SFMLWindow()
{
    _window->close();
}

bool LE::SFMLWindow::isOpen()
{
    return _window->isOpen();
}

void LE::SFMLWindow::close()
{
    _window->close();
}

void LE::SFMLWindow::clear()
{
    _window->clear();
}

void LE::SFMLWindow::display()
{
    _window->display();
}

const std::string& LE::SFMLWindow::getTitle()
{
    return _title;
}

void LE::SFMLWindow::setTitle(const std::string& title)
{
    _title = title;
    _window->setTitle(_title);
}

unsigned int LE::SFMLWindow::getWidth()
{
    return _width;
}

unsigned int LE::SFMLWindow::getHeight()
{
    return _height;
}

const std::shared_ptr<sf::RenderWindow>& LE::SFMLWindow::getWindow() const {
    return _window;
}
