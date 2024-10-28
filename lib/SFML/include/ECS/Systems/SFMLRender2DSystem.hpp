/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFMLRender2DSystem
*/

#ifndef SFMLRENDER2DSYSTEM_HPP_
    #define SFMLRENDER2DSYSTEM_HPP_

    #include "ECS/Systems/IRender2DSystem.hpp"
    #include "SFMLEngine.hpp"
    #include <memory>

class SFMLRender2DSystem : public IRender2DSystem {
    public:
        SFMLRender2DSystem(std::shared_ptr<LE::IEngine> &engine);
        ~SFMLRender2DSystem();

        void update(LE::Ecs *ecs, float dt) override;

    protected:
        std::shared_ptr<LE::IEngine> _engine;
    private:
};

#endif /* !SFMLRENDER2DSYSTEM_HPP_ */
