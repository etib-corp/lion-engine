/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IScene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include <memory>

    #include "interface/IEventManager.hpp"
    #include "interface/ISpriteComponent.hpp"
    #include "interface/ICameraComponent.hpp"

    #include "interface/GUI/IManager.hpp"

    #include "ECS/Ecs.hpp"

    #include "ECS/Components/BoxComponent.hpp"
    #include "ECS/Components/HealthComponent.hpp"

    #include "ECS/Systems/PatternSystem.hpp"
    #include "ECS/Systems/CollisionSystem.hpp"
    #include "ECS/Systems/MoveSystem.hpp"
    #include "ECS/Systems/ShootPatternSystem.hpp"

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
            std::shared_ptr<T> registerSystem()
            {
                return _ecs->registerSystem<T>();
            }

            template <typename T>
            void setSignature(Signature signature)
            {
                _ecs->setSignature<T>(signature);
            }

            template <typename T>
            std::shared_ptr<T> getSystem()
            {
                return _ecs->getSystem<T>();
            }

        protected:
            virtual void init();
            std::shared_ptr<Ecs> _ecs;
            std::shared_ptr<IEventManager> _eventManager;
            std::shared_ptr<LE::GUI::IManager> _guiManager;
            LE::IEngine *_engine;
            friend class IEngine;
        private:
    };

} // namespace LE

#endif /* !SCENE_HPP_ */
