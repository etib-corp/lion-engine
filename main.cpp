/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** main
*/

#include "GraphicalLib.hpp"
#include <thread>

int main()
{
    LE::GraphicalLib lib("./build/lib/SFML/liblion-engine-SFML.so");

    std::shared_ptr<LE::IEngine> engine = lib.createEngine();
    std::shared_ptr<LE::IWindow> window = engine->createWindow(800, 600, "SFML Window");

    while (window->isOpen()) {
        window->clear();
        window->display();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    return 0;
}
