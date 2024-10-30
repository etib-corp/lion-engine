/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFMLRender2DSystem
*/

#ifndef SFMLRENDER2DSYSTEM_HPP_
    #define SFMLRENDER2DSYSTEM_HPP_

    #include "ECS/Systems/IRender2DSystem.hpp"

namespace LE {
    class IEngine;
}

class SFMLRender2DSystem : public IRender2DSystem {
    public:
        SFMLRender2DSystem(void);
        ~SFMLRender2DSystem();

        void update(LE::Ecs *ecs, float dt) override;

        void setEngine(LE::IEngine *engine) { _engine = engine; }

    protected:
        LE::IEngine *_engine;
    private:
};

#endif /* !SFMLRENDER2DSYSTEM_HPP_ */
