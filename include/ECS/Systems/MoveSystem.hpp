/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include "ECS/SystemManager.hpp"
#include "ECS/Components/TransformComponent.hpp"
#include "ECS/Components/MotionComponent.hpp"

/**
 * @class MoveSystem
 * @brief The MoveSystem class is responsible for moving entities
 */
class MoveSystem : public System
{
public:
    /**
     * @brief Construct a new MoveSystem object
     */
    MoveSystem();

    /**
     * @brief Destroy the MoveSystem object
     */
    ~MoveSystem();

    /**
     * @brief Update the system
     * This function will be used to update the system
     */
    void update(LE::Ecs *ecs, float delta);

protected:
private:
};

#endif /* !MOVESYSTEM_HPP_ */
