/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEngine
*/

#include "SFMLEngine.hpp"

extern "C" {
    std::shared_ptr<LE::IEngine> createEngine()
    {
        return std::make_shared<LE::SFMLEngine>();
    }
}
