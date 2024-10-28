/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ITextField
*/

#include "GUI/ITextField.hpp"

void LE::GUI::ITextField::setMaxChar(unsigned int maxChar)
{
    _maxChar = maxChar;
}

void LE::GUI::ITextField::onClick()
{
    _isFocus = !_isFocus;
}

void LE::GUI::ITextField::onHover()
{
    Color *bgColor = _background->getColor();

    bgColor->setAlpha(100);
    _background->setColor(bgColor);
}

void LE::GUI::ITextField::onUnhover()
{
    Color *bgColor = _background->getColor();

    bgColor->setAlpha(255);
    _background->setColor(bgColor);
}

std::string LE::GUI::ITextField::getInputContent() const
{
    return _input->getContent();
}

std::shared_ptr<LE::IText> LE::GUI::ITextField::getInput() const
{
    return _input;
}
