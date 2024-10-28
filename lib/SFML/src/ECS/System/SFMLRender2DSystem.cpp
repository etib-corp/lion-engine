/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFMLRender2DSytem
*/

#include "ECS/Systems/SFMLRender2DSystem.hpp"

SFMLRender2DSystem::SFMLRender2DSystem(std::shared_ptr<LE::IEngine> &engine)
    : _engine(engine)
{
}

SFMLRender2DSystem::~SFMLRender2DSystem()
{
}

void SFMLRender2DSystem::update(LE::Ecs *ecs, float dt)
{
    std::shared_ptr<LE::SFMLWindow> window = _engine->getWindow<LE::SFMLWindow>();

    for (auto &entity : _entities) {
        auto &sprite = ecs->getComponent<LE::ISpriteComponent>(entity);
        auto &transform = ecs->getComponent<TransformComponent>(entity);

        auto SFMLSprite = dynamic_cast<LE::SFMLSpriteComponent *>(&sprite);
    }
}
