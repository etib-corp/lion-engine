/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** IRender2DSystems
*/

#ifndef IRENDER2DSYSTEMS_HPP_
    #define IRENDER2DSYSTEMS_HPP_

    #include "ECS/SystemManager.hpp"
    #include "interface/ISpriteComponent.hpp"
    #include "ECS/Components/TransformComponent.hpp"
    #include "ECS/Ecs.hpp"

class IRender2DSystem : public System {
    public:
        virtual ~IRender2DSystem() = default;

        virtual void update(LE::Ecs *ecs, float dt) = 0;

    protected:
    private:
};

#endif /* !IRENDER2DSYSTEMS_HPP_ */
