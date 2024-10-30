/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLCameraSystem
*/

#pragma once

#include "ECS/Systems/ICameraSystem.hpp"

namespace LE {
    class IEngine;
}

class SFMLCameraSystem : public LE::ICameraSystem {
    public:
        SFMLCameraSystem();
        ~SFMLCameraSystem();

        void update(LE::Ecs *ecs, float dt) override;

        void setEngine(LE::IEngine *engine) { _engine = engine; }

    protected:
        LE::IEngine *_engine;
};