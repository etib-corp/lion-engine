/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IContainer
*/

#include "GUI/IContainer.hpp"

void LE::GUI::IContainer::addChildren(std::shared_ptr<IComponent> child)
{
    _children.push_back(child);
}

void LE::GUI::IContainer::removeChildren(unsigned int id)
{
    for (auto it = _children.begin(); it != _children.end(); it++) {
        if ((*it)->getId() == id) {
            _children.erase(it);
            return;
        }
    }
}
