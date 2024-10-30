/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** CollisionSystem
*/

#ifndef COLLISIONSYSTEM_HPP_
#define COLLISIONSYSTEM_HPP_

#include "ECS/SystemManager.hpp"
#include "ECS/Components/HurtBoxComponent.hpp"
#include "ECS/Components/HitBoxComponent.hpp"
#include "ECS/Components/TransformComponent.hpp"
// #include "Shapes/Rectangle.hpp"

/**
 * @class CollisionSystem
 * @brief The CollisionSystem class is responsible for handling collisions
 */
class CollisionSystem : public System
{
public:
    /**
     * @brief Construct a new CollisionSystem object
     */
    CollisionSystem();

    /**
     * @brief Destroy the CollisionSystem object
     */
    ~CollisionSystem();

    /**
     * @brief Update the system
     * This function will be used to update the system
     */
    void update(LE::Ecs *ecs, float dt) override;

protected:
    // std::unique_ptr<LE::Shapes::Rectangle> _rectangle;
private:
};

#endif /* !COLLISIONSYSTEM_HPP_ */
