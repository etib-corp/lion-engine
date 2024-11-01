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
    _ecs->registerComponent<std::shared_ptr<LE::ICameraComponent>>();
    _ecs->registerComponent<ShootPatternComponent>();
    _ecs->registerComponent<AnimatedSpriteComponent>();

    _ecs->registerSystem<CollisionSystem>();
    _ecs->registerSystem<MoveSystem>();
    _ecs->registerSystem<PatternSystem>();
    _ecs->registerSystem<ShootPatternSystem>();
    _ecs->registerSystem<AnimatedSpriteSystem>();

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

    Signature AnimatedSpriteSignature;
    AnimatedSpriteSignature.set(_ecs->getComponentType<std::shared_ptr<LE::ISpriteComponent>>());
    AnimatedSpriteSignature.set(_ecs->getComponentType<AnimatedSpriteComponent>());
    _ecs->setSignature<AnimatedSpriteSystem>(AnimatedSpriteSignature);

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
    _ecs->update(_engine->getDeltaTime());
    _eventManager->pollEvents();
}

void LE::Scene::setPlaylist(std::shared_ptr<LE::Sound::Playlist> playlist)
{
    _playlist = playlist;
}

std::shared_ptr<LE::Sound::Playlist> LE::Scene::getPlaylist()
{
    return _playlist;
}
