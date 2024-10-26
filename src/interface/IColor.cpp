/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IColor
*/

#include "IColor.hpp"

void LE::IColor::setRed(unsigned char r)
{
    _red = r;
}

void LE::IColor::setGreen(unsigned char g)
{
    _green = g;
}

void LE::IColor::setBlue(unsigned char b)
{
    _blue = b;
}

void LE::IColor::setAlpha(unsigned char a)
{
    _alpha = a;
}

void LE::IColor::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    _red = r;
    _green = g;
    _blue = b;
    _alpha = a;
}

unsigned char LE::IColor::getRed() const
{
    return _red;
}

unsigned char LE::IColor::getGreen() const
{
    return _green;
}

unsigned char LE::IColor::getBlue() const
{
    return _blue;
}

unsigned char LE::IColor::getAlpha() const
{
    return _alpha;
}