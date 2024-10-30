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

void LE::GUI::IContainer::init()
{
    for (auto &child : _children) {
        child->init();
    }
}

void LE::GUI::IContainer::setBackground(LE::IShape *background)
{
    _background = background;
}

void LE::GUI::IContainer::setBackgroundColor(LE::Color *color)
{
    _background->setColor(color);
}

void LE::GUI::IContainer::draw()
{
    if (_background != nullptr) {
        _background->draw();
    }

    float totalHeight = 0.0f;

    for (auto child : _children) {
        if (child->getWidth() > _width) {
            _width = child->getWidth();
        }
        totalHeight += child->getHeight();
    }
    _height = totalHeight > _height ? totalHeight : _height;

    auto lastPos = _y + _height - ((_height / 2) - (totalHeight / 2));
    for (auto child : _children) {
        child->setPos(_x + (_width / 2) - (child->getWidth() / 2), lastPos - child->getHeight());
        lastPos -= child->getHeight();
        child->draw();
    }
}