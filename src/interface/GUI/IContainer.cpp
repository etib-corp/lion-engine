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
    if (_background != nullptr)
        _background->init();
    if (_children.empty())
        return;
    for (auto &child : _children) {
        child->init();
    }
}

void LE::GUI::IContainer::setBackground(std::shared_ptr<LE::IShape> background)
{
    _background = background;
}

void LE::GUI::IContainer::setBackgroundColor(std::shared_ptr<LE::Color> color)
{
    if (_background == nullptr) {
        std::cerr << "No background set" << std::endl;
        return;
    }
    _background->setColor(color);
}

void LE::GUI::IContainer::draw()
{
    if (_background != nullptr) {
        _background->resize(_width, _height);
        _background->setPosition({_x, _y, 0});
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

void LE::GUI::IContainer::setFont(std::shared_ptr<LE::IFont> font)
{
    for (auto &child : _children) {
        child->setFont(font);
    }
}