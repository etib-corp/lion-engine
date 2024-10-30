/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLCameraSystem
*/

#include "ECS/Systems/SFMLCameraSystem.hpp"
#include "SFMLEngine.hpp"

SFMLCameraSystem::SFMLCameraSystem()
{
}

SFMLCameraSystem::~SFMLCameraSystem()
{
}

void SFMLCameraSystem::update(LE::Ecs *ecs, float dt)
{
    std::shared_ptr<LE::SFMLWindow> window = _engine->getWindow<LE::SFMLWindow>();
    for (auto &entity : _entities) {
        auto &camera = ecs->getComponent<std::shared_ptr<LE::ICameraComponent>>(entity);
        auto &transform = ecs->getComponent<TransformComponent>(entity);
        auto SFMLCamera = dynamic_cast<LE::SFMLCameraComponent *>(camera.get());
        if (SFMLCamera) {
            window->getWindow()->setView(*SFMLCamera->view);
        }
    }
}