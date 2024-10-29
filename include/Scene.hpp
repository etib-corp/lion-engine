/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IScene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include <memory>
    #include "ECS/Ecs.hpp"
    #include "interface/IEventManager.hpp"
    #include "ECS/Components/BoxComponent.hpp"
    #include "ECS/Components/HealthComponent.hpp"
    #include "interface/ISpriteComponent.hpp"

namespace LE
{
    class IEngine;
    class Scene {
        public:
            Scene(const std::shared_ptr<LE::IEngine> &engine);
            ~Scene();

            virtual void init();

            void draw();

            std::shared_ptr<LE::Ecs> &getEcs() { return _ecs; }

            std::shared_ptr<LE::IEventManager> &getEventManager() { return _eventManager; }

        protected:
            std::shared_ptr<Ecs> _ecs;
            std::shared_ptr<IEventManager> _eventManager;
            std::shared_ptr<LE::IEngine> _engine;
        private:
    };

} // namespace LE

#endif /* !SCENE_HPP_ */
