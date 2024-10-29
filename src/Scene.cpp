/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Scene
*/

#include "Scene.hpp"
#include "interface/IEngine.hpp"

LE::Scene::Scene(LE::IEngine &engine)
{
    _ecs = std::make_shared<Ecs>();
    _eventManager = engine.createEventManager();
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
