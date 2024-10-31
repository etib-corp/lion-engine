/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** EntityManager
*/

#include "ECS/EntityManager.hpp"

LE::EntityManager::EntityManager()
{
    _livingEntityCount = 0;
    for (Entity entity = 0; entity < MAX_ENTITIES; entity++) {
        _availableEntities.push(entity);
    }
}

LE::EntityManager::~EntityManager()
{
}

Entity LE::EntityManager::createEntity(void)
{
    if (_livingEntityCount >= MAX_ENTITIES) {
        throw EntityManagerError("Maximum number of entities reached", "The maximum number of entities has been reached", "Try to destroy some entities");
    }
    Entity entity = _availableEntities.front();
    _availableEntities.pop();
    _livingEntityCount++;
    return entity;
}

Entity LE::EntityManager::createEntity(Entity entity)
{
    if (entity >= MAX_ENTITIES || entity < 0) {
        throw EntityManagerError("Entity out of range", "The entity is out of range", "Try to use a valid entity");
    }
    if (_livingEntityCount >= MAX_ENTITIES) {
        throw EntityManagerError("Maximum number of entities reached", "The maximum number of entities has been reached", "Try to destroy some entities");
    }
    _livingEntityCount++;
    return entity;
}

void LE::EntityManager::destroyEntity(Entity entity)
{
    if (entity >= MAX_ENTITIES || entity < 0) {
        throw EntityManagerError("Entity out of range", "The entity is out of range. You can't destroy an invalid entity.", "Try to use a valid entity");
    }
    _availableEntities.push(entity);
    _signatures[entity] = 0;
    _livingEntityCount--;
}

void LE::EntityManager::setSignature(Entity entity, Signature signature)
{
    if (entity >= MAX_ENTITIES || entity < 0) {
        throw EntityManagerError("Entity out of range", "The entity is out of range. You can't set signature on an invalid entity.", "Try to use a valid entity");
    }
    _signatures[entity] = signature;
}

Signature LE::EntityManager::getSignature(Entity entity)
{
    if (entity >= MAX_ENTITIES || entity < 0) {
        throw EntityManagerError("Entity out of range", "The entity is out of range. You can't get signature on an invalid entity.", "Try to use a valid entity");
    }
    return _signatures[entity];
}
