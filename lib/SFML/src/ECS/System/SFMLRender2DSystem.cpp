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
        std::cout << "Entity: " << entity << std::endl;
        auto &sprite = ecs->getComponent<LE::ISpriteComponent>(entity);
        auto &transform = ecs->getComponent<TransformComponent>(entity);

        auto SFMLSprite = dynamic_cast<LE::SFMLSpriteComponent *>(&sprite);
        if (SFMLSprite) {
            SFMLSprite->sprite->setPosition(transform.position.x, transform.position.y);
            SFMLSprite->sprite->scale(transform.scale.x, transform.scale.y);
            SFMLSprite->sprite->rotate(transform.rotation.z);
            window->getWindow()->draw(*SFMLSprite->sprite);
        }
    }
}
