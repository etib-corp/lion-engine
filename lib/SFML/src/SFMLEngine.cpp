/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEngine
*/

#include "SFMLEngine.hpp"

std::shared_ptr<LE::IEngine> LE::createEngine()
{
    return std::make_shared<LE::SFMLEngine>();
}