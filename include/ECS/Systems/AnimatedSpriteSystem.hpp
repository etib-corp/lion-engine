/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** AnimatedSpriteSystem
*/

#ifndef ANIMATEDSPRITESYSTEM_HPP_
#define ANIMATEDSPRITESYSTEM_HPP_

#include "ECS/Components/AnimatedSpriteComponent.hpp"
#include "interface/ISpriteComponent.hpp"
#include "ECS/SystemManager.hpp"

class AnimatedSpriteSystem : public System {
    public:
        AnimatedSpriteSystem();
        ~AnimatedSpriteSystem();

        void update(LE::Ecs *ecs, float dt) override;

    protected:
    private:
};

#endif /* !ANIMATEDSPRITESYSTEM_HPP_ */
