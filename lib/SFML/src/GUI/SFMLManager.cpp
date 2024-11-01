/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLManager
*/

#include "GUI/SFMLManager.hpp"

LE::GUI::SFMLManager::SFMLManager(std::shared_ptr<LE::IWindow> window)
{
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _width = _window->getWidth();
    _height = _window->getHeight();
    _x = 0;
    _y = 0;
    init();
}

LE::GUI::SFMLManager::~SFMLManager()
{
}

void LE::GUI::SFMLManager::init()
{
    std::cout << "Init manager" << std::endl;
}
