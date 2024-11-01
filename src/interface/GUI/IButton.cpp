/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IButton
*/

#include "GUI/IButton.hpp"

void LE::GUI::IButton::onClick()
{
    auto color = _background->getColor();

    color->setAlpha(0);
    _background->setColor(color);

    if (_onClick)
        _onClick();
}

void LE::GUI::IButton::onHover()
{
    auto color = _background->getColor();

    color->setAlpha(100);
    _background->setColor(color);
    if (_onHover)
        _onHover();
}

void LE::GUI::IButton::onUnhover()
{
    auto color = _background->getColor();

    color->setAlpha(255);
    _background->setColor(color);
    if (_onUnhover)
        _onUnhover();
}

void LE::GUI::IButton::setOnClickCallback(std::function<void()> onClick)
{
    _onClick = onClick;
}

void LE::GUI::IButton::setOnHoverCallback(std::function<void()> onHover)
{
    _onHover = onHover;
}

void LE::GUI::IButton::setOnUnhoverCallback(std::function<void()> onUnhover)
{
    _onUnhover = onUnhover;
}

void LE::GUI::IButton::setContent(std::shared_ptr<LE::GUI::IText> text)
{
    _text = text;
}

void LE::GUI::IButton::setContent(const std::string &content)
{
    _text->setContent(content);
}

std::shared_ptr<LE::GUI::IText> LE::GUI::IButton::getContent() const
{
    return _text;
}

std::string LE::GUI::IButton::getContentString() const
{
    return _text->getContent();
}