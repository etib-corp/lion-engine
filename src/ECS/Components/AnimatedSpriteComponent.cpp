/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** AnimatedSpriteComponent
*/

#include "ECS/Components/AnimatedSpriteComponent.hpp"


AnimatedSpriteComponent *createAnimatedSpriteComponent(std::shared_ptr<LE::ISpriteComponent> sprite, int frameWidth, int frameHeight)
{
    auto *animatedSprite = new AnimatedSpriteComponent;

    animatedSprite->textureWidth = sprite->width;
    animatedSprite->textureHeight = sprite->height;
    animatedSprite->currentAnimation = "";
    animatedSprite->animations = {};
    animatedSprite->elapsedTime = 0;
    animatedSprite->frameWidth = frameWidth;
    animatedSprite->frameHeight = frameHeight;
    sprite->rect = {0, 0, frameWidth, frameHeight};
    return animatedSprite;
}

void addAnimation(AnimatedSpriteComponent &animatedSprite, const std::string &name, std::vector<unsigned int> frames, std::function<void(AnimatedSpriteComponent &)> callback, float frameTime, bool loop)
{
    auto animation = std::make_shared<Animation>();

    animation->frames = frames;
    animation->callback = callback;
    animation->frameTime = frameTime;
    animation->loop = loop;
    animation->currentFrame = 0;
    animatedSprite.animations[name] = animation;
}

LE::Vector4<int> getFrameIndex(unsigned int index, AnimatedSpriteComponent &animatedSprite)
{
    int x = index % (animatedSprite.textureWidth / animatedSprite.frameWidth);
    int y = index / (animatedSprite.textureWidth / animatedSprite.frameWidth);
    return {x * animatedSprite.frameWidth, y * animatedSprite.frameHeight, animatedSprite.frameWidth, animatedSprite.frameHeight};
}
LE::Vector4<int> getNewFrame(AnimatedSpriteComponent &animatedSprite)
{
    std::shared_ptr<Animation> animation = animatedSprite.animations[animatedSprite.currentAnimation];

    if (animation->frames.empty())
        return {0, 0, animatedSprite.textureWidth, animatedSprite.textureHeight};
    LE::Vector4<int> frame = getFrameIndex(animation->frames[animation->currentFrame], animatedSprite);
    if (animation->currentFrame >= animation->frames.size()) {
        animation->currentFrame = 0;
        if (!animation->loop)
            animatedSprite.currentAnimation = "";
        animation->callback(animatedSprite);
    } else {
        animation->currentFrame++;
    }
    return frame;
}
