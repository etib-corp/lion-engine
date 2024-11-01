/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFMLRender2DSytem
*/

#include "ECS/Systems/SFMLRender2DSystem.hpp"
#include "SFMLEngine.hpp"

SFMLRender2DSystem::SFMLRender2DSystem(void)
{
}

SFMLRender2DSystem::~SFMLRender2DSystem()
{
}

void SFMLRender2DSystem::update(LE::Ecs *ecs, float dt)
{
    std::shared_ptr<LE::SFMLWindow> window = _engine->getWindow<LE::SFMLWindow>();
    for (auto &entity : _entities) {
        auto &sprite = ecs->getComponent<std::shared_ptr<LE::ISpriteComponent>>(entity);
        auto &transform = ecs->getComponent<TransformComponent>(entity);
        auto SFMLSprite = dynamic_cast<LE::SFMLSpriteComponent *>(sprite.get());
        if (SFMLSprite) {
            SFMLSprite->sprite->setPosition(transform.position.x, transform.position.y);
            SFMLSprite->sprite->setTextureRect(sf::IntRect(sprite->rect.x, sprite->rect.y, sprite->rect.z, sprite->rect.w));
            SFMLSprite->sprite->setScale(transform.scale.x, transform.scale.y);
            SFMLSprite->sprite->setRotation(transform.rotation.z);
            window->getWindow()->draw(*SFMLSprite->sprite);
        }
    }
}
