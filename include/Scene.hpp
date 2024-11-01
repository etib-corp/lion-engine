/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IScene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include <memory>
    #include <map>
    #include "ECS/Ecs.hpp"
    #include "interface/IEventManager.hpp"
    #include "ECS/Components/BoxComponent.hpp"
    #include "ECS/Components/HealthComponent.hpp"
    #include "interface/ISpriteComponent.hpp"
    #include "interface/ICameraComponent.hpp"
    #include "ECS/Systems/PatternSystem.hpp"
    #include "ECS/Systems/CollisionSystem.hpp"
    #include "ECS/Systems/MoveSystem.hpp"
    #include "ECS/Systems/ShootPatternSystem.hpp"
    #include "ECS/Systems/ICameraSystem.hpp"
    #include "ECS/Systems/AnimatedSpriteSystem.hpp"
    #include "Sound/Playlist.hpp"

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

            void setPlaylist(std::shared_ptr<LE::Sound::Playlist> playlist);

            std::shared_ptr<LE::Sound::Playlist> getPlaylist();

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
            LE::IEngine *_engine;
            std::shared_ptr<LE::Sound::Playlist> _playlist;
            friend class IEngine;
        private:
    };

} // namespace LE

#endif /* !SCENE_HPP_ */
