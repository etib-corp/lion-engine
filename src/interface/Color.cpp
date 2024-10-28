/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Color
*/

#include "Color.hpp"

LE::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    _red = r;
    _green = g;
    _blue = b;
    _alpha = a;
}

LE::Color::~Color()
{
}

void LE::Color::setRed(unsigned char r)
{
    _red = r;
}

void LE::Color::setGreen(unsigned char g)
{
    _green = g;
}

void LE::Color::setBlue(unsigned char b)
{
    _blue = b;
}

void LE::Color::setAlpha(unsigned char a)
{
    _alpha = a;
}

void LE::Color::setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    _red = r;
    _green = g;
    _blue = b;
    _alpha = a;
}

unsigned char LE::Color::getRed() const
{
    return _red;
}

unsigned char LE::Color::getGreen() const
{
    return _green;
}

unsigned char LE::Color::getBlue() const
{
    return _blue;
}

unsigned char LE::Color::getAlpha() const
{
    return _alpha;
}