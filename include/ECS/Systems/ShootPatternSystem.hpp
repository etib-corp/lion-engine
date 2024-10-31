/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** ShootPatternSystem
*/

#pragma once

#include "ECS/SystemManager.hpp"
#include "ECS/Components/ShootPatternComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Components/MotionComponent.hpp"

/**
 * @class ShootPatternSystem
 * @brief The ShootPatternSystem class is responsible for handling shoot patterns
 */
class ShootPatternSystem : public System
{
public:
    /**
     * @brief Construct a new ShootPatternSystem object
     */
    ShootPatternSystem();

    /**
     * @brief Destroy the ShootPatternSystem object
     */
    ~ShootPatternSystem();

    /**
     * @brief Update the system
     * This function will be used to update the system
     */
    void update(LE::Ecs *ecs, float dt) override;

protected:
};
