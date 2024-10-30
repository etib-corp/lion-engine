/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ICameraSystem
*/

#pragma once

#include "ECS/SystemManager.hpp"
#include "interface/ICameraComponent.hpp"
#include "ECS/Ecs.hpp"

namespace LE {
    class ICameraSystem : public System {
        public:
            virtual ~ICameraSystem() = default;

            virtual void update(LE::Ecs *ecs, float dt) = 0;
    };
}