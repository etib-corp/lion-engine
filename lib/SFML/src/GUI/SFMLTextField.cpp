/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** \
*/

#include "GUI/SFMLTextField.hpp"

LE::GUI::SFMLTextField::SFMLTextField(const LE::Vector3<float> &pos, const std::string &label, const std::string &placeholder)
{
    _label = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(pos.x, pos.y, 0), label);
    _input = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(pos.x, pos.y + 20, 0), placeholder);
    _isFocus = false;
    _maxChar = 18;
    _x = pos.x;
    _y = pos.y;
    addChildren(_label);
    addChildren(_input);
}

LE::GUI::SFMLTextField::~SFMLTextField()
{
}
