/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLSpriteComponent
*/

#include "SFMLSpriteComponent.hpp"

std::shared_ptr<LE::ISpriteComponent> LE::Sprite::createSpriteComponent(const std::string &path, std::shared_ptr<LE::IWindow> window)
{
    auto sprite = std::make_shared<LE::SFMLSpriteComponent>();
    sprite->path = path;
    sprite->window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    sprite->texture = std::make_shared<sf::Texture>();
    sprite->texture->loadFromFile(path);
    sprite->sprite = std::make_shared<sf::Sprite>(*sprite->texture);
    sprite->width = sprite->texture->getSize().x;
    sprite->height = sprite->texture->getSize().y;
    sprite->hidden = false;
    sprite->rect = {0, 0, static_cast<int>(sprite->width), static_cast<int>(sprite->height)};
    return sprite;
}

std::shared_ptr<LE::ISpriteComponent> LE::Sprite::createSpriteComponentFromMemory(const std::string &data, std::shared_ptr<LE::IWindow> window)
{
    auto sprite = std::make_shared<LE::SFMLSpriteComponent>();
    sprite->path = "loaded from memory";
    sprite->window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    sprite->texture = std::make_shared<sf::Texture>();
    sprite->texture->loadFromMemory(data.c_str(), data.size());
    sprite->sprite = std::make_shared<sf::Sprite>(*sprite->texture);
    sprite->width = sprite->texture->getSize().x;
    sprite->height = sprite->texture->getSize().y;
    sprite->hidden = false;
    return sprite;
}


void LE::Sprite::drawSpriteComponent(std::shared_ptr<LE::ISpriteComponent> sprite)
{
    LE::SFMLSpriteComponent *spriteComponent = dynamic_cast<LE::SFMLSpriteComponent *>(sprite.get());
    spriteComponent->window->getWindow()->draw(*spriteComponent->sprite);
}
