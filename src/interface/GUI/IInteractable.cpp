/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IInteractable
*/

#include "GUI/IInteractable.hpp"

void LE::GUI::IInteractable::update()
{
    if (isHover()) {
        onHover();
        if (isClicked()) {
            onClick();
        }
    } else {
        onUnhover();
    }
}
