/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IText
*/

#include "IText.hpp"

void LE::IText::setContent(const std::string &content)
{
    _content = content;
}

void LE::IText::setFont(std::shared_ptr<IFont> font)
{
    _font = font;
}

void LE::IText::setColor(std::shared_ptr<IColor> color)
{
    _color = color;
}

void LE::IText::setCharacterSize(unsigned int size)
{
    _font->setHeight(size);
}

std::shared_ptr<LE::IFont> LE::IText::getFont() const
{
    return _font;
}

std::shared_ptr<LE::IColor> LE::IText::getColor() const
{
    return _color;
}

std::string LE::IText::getContent() const
{
    return _content;
}
