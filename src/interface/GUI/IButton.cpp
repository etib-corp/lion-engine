/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IButton
*/

#include "GUI/IButton.hpp"

void LE::GUI::IButton::onClick()
{
    if (_onClick)
        _onClick();
}

void LE::GUI::IButton::onHover()
{
    if (_onHover)
        _onHover();
}

void LE::GUI::IButton::onUnhover()
{
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
