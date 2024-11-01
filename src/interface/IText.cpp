/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IText
*/

#include "GUI/IText.hpp"

void LE::GUI::IText::setContent(const std::string &content)
{
    _content = content;
}

void LE::GUI::IText::setFont(std::shared_ptr<IFont> font)
{
    _font = font;
}

void LE::GUI::IText::setCharacterSize(unsigned int size)
{
    _font->setHeight(size);
}

std::shared_ptr<LE::IFont> LE::GUI::IText::getFont() const
{
    return _font;
}

std::string LE::GUI::IText::getContent() const
{
    return _content;
}
