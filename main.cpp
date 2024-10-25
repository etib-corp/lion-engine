/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** main
*/

#include "SFMLWindow.hpp"

#include <thread>

int main()
{
    std::shared_ptr<LE::IWindow> window = std::make_shared<LE::SFMLWindow>(800, 600, "main");
    unsigned int width = 800;
    unsigned int height = 600;
    std::string title = "main";

    while (window->isOpen()) {
        window->setTitle(title);
        title += "!";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}