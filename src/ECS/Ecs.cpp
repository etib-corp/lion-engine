/*
** EPITECH PROJECT, 2024
** client
** File description:
** Ecs
*/

#include "ECS/Ecs.hpp"

LE::Ecs::Ecs()
{
    _componentManager = std::make_unique<ComponentManager>();
    _entityManager = std::make_unique<EntityManager>();
    _systemManager = std::make_unique<SystemManager>();
}

LE::Ecs::~Ecs()
{
}

Entity LE::Ecs::createEntity()
{
    return _entityManager->createEntity();
}

Entity LE::Ecs::createEntity(Entity entity)
{
    return _entityManager->createEntity(entity);
}

void LE::Ecs::destroyEntity(Entity entity)
{
    _entityManager->destroyEntity(entity);
    _componentManager->entityDestroyed(entity);
    _systemManager->entityDestroyed(entity);
}

void LE::Ecs::update(float dt)
{
    _systemManager->update(this, dt);
}

void LE::Ecs::setCameraEntity(Entity entity)
{
    _cameraEntity = entity;
}

Entity LE::Ecs::getCameraEntity() const
{
    return _cameraEntity;
}

void *LE::Ecs::getScene() const
{
    return _scene;
}

void LE::Ecs::setScene(void *scene)
{
    _scene = scene;
}
