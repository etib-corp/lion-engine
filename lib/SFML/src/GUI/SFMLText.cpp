/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLText
*/

#include "GUI/SFMLText.hpp"

LE::GUI::SFMLText::SFMLText(const LE::Vector3<float> &pos, std::shared_ptr<LE::IWindow> window, const std::string &content, Color *color)
{
    _content = content;
    _window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    _color = color == nullptr ? new Color(255, 255, 255, 255) : color;
    _font = nullptr;
    _text = new sf::Text();
    _x = pos.x;
    _y = pos.y;
}

LE::GUI::SFMLText::~SFMLText()
{
}

void LE::GUI::SFMLText::init()
{
    sf::Color sfmlColor(_color->getRed(), _color->getGreen(), _color->getBlue(), _color->getAlpha());

    _text->setFillColor(sfmlColor);
    _text->setString(_content);
    _text->setFont(dynamic_cast<LE::SFMLFont *>(_font.get())->_font);
}

void LE::GUI::SFMLText::setContent(const std::string &content)
{
    LE::IText::setContent(content);

    _text->setString(content);
}

void LE::GUI::SFMLText::setFont(std::shared_ptr<IFont> font)
{
    LE::IText::setFont(font);

    _text->setFont(dynamic_cast<LE::SFMLFont *>(font.get())->_font);
}

void LE::GUI::SFMLText::setColor(Color *color)
{
    LE::IShape::setColor(color);

    sf::Color sfmlColor(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());

    _text->setFillColor(sfmlColor);
}

float LE::GUI::SFMLText::getWidth() const
{
    return _text->getGlobalBounds().width;
}

float LE::GUI::SFMLText::getHeight() const
{
    return _text->getGlobalBounds().height;
}

void LE::GUI::SFMLText::draw()
{
    _text->setPosition(sf::Vector2f(_x, _y));
    _window->getWindow()->draw(*_text);
}