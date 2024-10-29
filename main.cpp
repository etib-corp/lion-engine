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

    
    return 0;
}
