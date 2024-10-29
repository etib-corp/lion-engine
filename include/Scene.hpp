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

namespace LE
{
    class IEngine;
    class Scene {
        public:
            Scene(LE::IEngine &engine);
            ~Scene();

            void init();

            void draw();

        protected:
            std::shared_ptr<Ecs> _ecs;
            std::shared_ptr<IEventManager> _eventManager;
        private:
    };

} // namespace LE

#endif /* !SCENE_HPP_ */
