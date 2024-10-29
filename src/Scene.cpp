/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Scene
*/

#include "Scene.hpp"
#include "interface/IEngine.hpp"

LE::Scene::Scene(const std::shared_ptr<LE::IEngine> &engine)
{
    _ecs = std::make_shared<Ecs>();
    _ecs->registerComponent<std::shared_ptr<LE::ISpriteComponent>>();
    _ecs->registerComponent<TransformComponent>();
    _eventManager = engine->createEventManager();
    _engine = engine;
}

LE::Scene::~Scene()
{
}

void LE::Scene::init()
{
}

void LE::Scene::draw()
{
    _ecs->update(0.0f);
    _eventManager->pollEvents();
}
