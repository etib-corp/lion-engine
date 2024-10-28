/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLText
*/

#include "SFMLText.hpp"

LE::SFMLText::SFMLText(const std::string &content, IColor *color)
{
    _content = content;
    _color = color;
    _font = nullptr;
    _text = new sf::Text();
}

LE::SFMLText::~SFMLText()
{
}

void LE::SFMLText::init()
{
    sf::Color sfmlColor(_color->getRed(), _color->getGreen(), _color->getBlue(), _color->getAlpha());

    _text->setFillColor(sfmlColor);
    _text->setString(_content);
    _text->setFont(dynamic_cast<LE::SFMLFont *>(_font.get())->_font);
}

void LE::SFMLText::setContent(const std::string &content)
{
    LE::IText::setContent(content);

    _text->setString(content);
}

void LE::SFMLText::setFont(std::shared_ptr<IFont> font)
{
    LE::IText::setFont(font);

    _text->setFont(dynamic_cast<LE::SFMLFont *>(font.get())->_font);
}

void LE::SFMLText::setColor(IColor *color)
{
    LE::IShape::setColor(color);

    sf::Color sfmlColor(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());

    _text->setFillColor(sfmlColor);
}
