/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Scene
*/

#include "Scene.hpp"
#include "interface/IEngine.hpp"

LE::Scene::Scene(LE::IEngine *engine)
{
    _ecs = std::make_shared<Ecs>();
    _ecs->setScene(this);
    _ecs->registerComponent<std::shared_ptr<LE::ISpriteComponent>>();
    _ecs->registerComponent<TransformComponent>();
    _ecs->registerComponent<HurtBox>();
    _ecs->registerComponent<HitBox>();
    _ecs->registerComponent<MotionComponent>();
    _ecs->registerComponent<PatternComponent>();


    Signature CollisionSignature;
    CollisionSignature.set(_ecs->getComponentType<TransformComponent>());
    CollisionSignature.set(_ecs->getComponentType<HitBox>());
    CollisionSignature.set(_ecs->getComponentType<HurtBox>());
    _ecs->setSignature<CollisionSystem>(CollisionSignature);

    Signature MoveSignature;
    MoveSignature.set(_ecs->getComponentType<TransformComponent>());
    MoveSignature.set(_ecs->getComponentType<MotionComponent>());
    _ecs->setSignature<MoveSystem>(MoveSignature);

    Signature PatternSignature;
    PatternSignature.set(_ecs->getComponentType<TransformComponent>());
    PatternSignature.set(_ecs->getComponentType<PatternComponent>());
    _ecs->setSignature<PatternSystem>(PatternSignature);

    Signature ShootPatternSignature;
    ShootPatternSignature.set(_ecs->getComponentType<TransformComponent>());
    ShootPatternSignature.set(_ecs->getComponentType<MotionComponent>());
    ShootPatternSignature.set(_ecs->getComponentType<ShootPatternComponent>());
    _ecs->setSignature<ShootPatternSystem>(ShootPatternSignature);

    _eventManager = engine->createEventManager();
    _engine = engine;
    _engine->createRender2DSystem(*_ecs);
    _engine->createCameraSystem(*_ecs);
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
