/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** AnimatedSpriteComponent
*/

#ifndef ANIMATEDSPRITECOMPONENT_HPP_
#define ANIMATEDSPRITECOMPONENT_HPP_

#include <unordered_map>
#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include "ECS/Ecs.hpp"
#include "interface/ISpriteComponent.hpp"

struct AnimatedSpriteComponent;

struct Animation {
    std::vector<unsigned int> frames;
    std::function<void(AnimatedSpriteComponent &)> callback;
    float frameTime;
    bool loop;
    int currentFrame;
};

struct AnimatedSpriteComponent {
    std::unordered_map<std::string, std::shared_ptr<Animation>> animations;
    std::string currentAnimation;
    int textureWidth;
    int textureHeight;
    float elapsedTime;
    int frameWidth;
    int frameHeight;
};

AnimatedSpriteComponent *createAnimatedSpriteComponent(std::shared_ptr<LE::ISpriteComponent> sprite, int frameWidth, int frameHeight);

void addAnimation(AnimatedSpriteComponent &animatedSprite, const std::string &name, std::vector<unsigned int> frames, std::function<void(AnimatedSpriteComponent &)> callback, float frameTime, bool loop);

LE::Vector4<int> getNewFrame(AnimatedSpriteComponent &animatedSprite);

#endif /* !ANIMATEDSPRITECOMPONENT_HPP_ */
