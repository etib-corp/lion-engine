/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** AnimatedSpriteSystem
*/

#include "ECS/Systems/AnimatedSpriteSystem.hpp"

AnimatedSpriteSystem::AnimatedSpriteSystem()
{
}

AnimatedSpriteSystem::~AnimatedSpriteSystem()
{
}

void AnimatedSpriteSystem::update(LE::Ecs *ecs, float dt)
{
    for (auto &entity : _entities) {
        auto &animatedSprite = ecs->getComponent<AnimatedSpriteComponent>(entity);
        auto &sprite = ecs->getComponent<std::shared_ptr<LE::ISpriteComponent>>(entity);

        if (animatedSprite.currentAnimation.empty())
            continue;
        animatedSprite.elapsedTime += dt;
        if (animatedSprite.elapsedTime >= (1000.0f / animatedSprite.animations[animatedSprite.currentAnimation]->frameTime)) {
            animatedSprite.elapsedTime = 0;
            sprite->rect = getNewFrame(animatedSprite);
        }
    }
}
