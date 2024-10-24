/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLFont
*/

#include "SFMLFont.hpp"

LE::SFMLFont::SFMLFont(const std::string &path, unsigned int height, unsigned int width)
{
    _path = path;
    _height = height;
    _width = width;
    _font = sf::Font();
}

LE::SFMLFont::~SFMLFont()
{
}

void LE::SFMLFont::init()
{
    _font.loadFromFile(_path);
}
