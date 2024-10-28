/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** main
*/

#include "SFMLEngine.hpp"
#include "GraphicalLib.hpp"

#include <thread>

int main()
{
    std::shared_ptr<LE::GraphicalLib> lib = std::make_shared<LE::GraphicalLib>();
    std::shared_ptr<LE::IEngine> engine = lib->createEngine();
    std::shared_ptr<LE::IWindow> window = engine->createWindow(800, 600, "Window");

    while (window->isOpen()) {
        window->clear();
        window->display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    return 0;
}