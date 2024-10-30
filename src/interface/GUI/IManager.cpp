/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IManager
*/

#include "GUI/IManager.hpp"

void LE::GUI::IManager::addChildren(std::shared_ptr<LE::GUI::IComponent> child)
{
    _id = 0;
    _lastID++;
    child->_id = _lastID;
    _children.push_back(child);
}
