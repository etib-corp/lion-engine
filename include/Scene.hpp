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
            Scene(LE::IEngine *engine);
            ~Scene();


            void draw();

            std::shared_ptr<LE::Ecs> &getEcs() { return _ecs; }

            std::shared_ptr<LE::IEventManager> &getEventManager() { return _eventManager; }


            template <typename T>
            void registerComponent()
            {
                _ecs->registerComponent<T>();
            }

            template <typename T>
            void registerSystem()
            {
                _ecs->registerSystem<T>();
            }
        protected:
            virtual void init();
            std::shared_ptr<Ecs> _ecs;
            std::shared_ptr<IEventManager> _eventManager;
            LE::IEngine *_engine;
            friend class IEngine;
        private:
    };

} // namespace LE

#endif /* !SCENE_HPP_ */