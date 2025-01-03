/*
** EPITECH PROJECT, 2024
** client
** File description:
** Ecs
*/

#pragma once

#include "ECS/common.hpp"
#include "ECS/ComponentManager.hpp"
#include "ECS/EntityManager.hpp"
#include "ECS/SystemManager.hpp"

namespace LE
{
    /**
     * @class Ecs
     * @brief The Ecs class is the main class of the ECS system. It is responsible for creating and destroying entities, and adding and removing components from entities
     */
    class Ecs
    {
    public:
        /**
         * @brief Construct a new Ecs object
         */
        Ecs();

        /**
         * @brief Destroy the Ecs object
         */
        ~Ecs();

        /**
         * @brief Create a new entity
         * @return Entity The entity that was created
         */
        Entity createEntity();

        /**
         * @brief Create a new entity
         * @param entity The entity to create
         * @return Entity The entity that was created
         */
        Entity createEntity(Entity entity);

        /**
         * @brief Destroy an entity
         * @param entity The entity to destroy
         */
        void destroyEntity(Entity entity);

        /**
         * @brief Register a component
         * @tparam T The component to register
         */
        template <typename T>
        void registerComponent()
        {
            _componentManager->registerComponent<T>();
        }

        /**
         * @brief Add a component to an entity
         * @tparam T The component to add
         * @param entity The entity to add the component to
         * @param component The component to add
         */
        template <typename T>
        void addComponent(Entity entity, T component)
        {
            _componentManager->addComponent<T>(entity, component);
            auto signature = _entityManager->getSignature(entity);
            signature.set(_componentManager->getComponentType<T>(), true);
            _entityManager->setSignature(entity, signature);
            _systemManager->entitySignatureChanged(entity, signature);
        }

        /**
         * @brief Remove a component from an entity
         * @tparam T The component to remove
         * @param entity The entity to remove the component from
         */
        template <typename T>
        void removeComponent(Entity entity)
        {
            _componentManager->removeComponent<T>(entity);
            auto signature = _entityManager->getSignature(entity);
            signature.set(_componentManager->getComponentType<T>(), false);
            _entityManager->setSignature(entity, signature);
            _systemManager->entitySignatureChanged(entity, signature);
        }

        /**
         * @brief Get a component from an entity
         * @tparam T The component to get
         * @param entity The entity to get the component from
         * @return T& The component
         */
        template <typename T>
        T &getComponent(Entity entity)
        {
            return _componentManager->getComponent<T>(entity);
        }

        template <typename T>
        std::vector<T> getComponents()
        {
            return _componentManager->getComponents<T>();
        }

        /**
         * @brief Get a component type
         * @tparam T The component to get the type of
         * @return ComponentType The component type
         */
        template <typename T>
        ComponentType getComponentType()
        {
            return _componentManager->getComponentType<T>();
        }

        /**
         * @brief Registers a new system of type T.
         *
         * This function registers a new system with the system manager and returns a shared pointer to the newly registered system.
         *
         * @tparam T The type of the system to be registered.
         * @return std::shared_ptr<T> A shared pointer to the newly registered system.
         */
        template <typename T>
        std::shared_ptr<T> registerSystem()
        {
            return _systemManager->registerSystem<T>();
        }

        /**
         * @brief Set the signature of a system
         *
         * @tparam T The system to set the signature of
         * @param signature The signature to set
         */
        template <typename T>
        void setSignature(Signature signature)
        {
            _systemManager->setSignature<T>(signature);
        }

        /**
         * @brief Update the ECS
         *
         * This function will be used to update the ECS by calling the update function of the system manager
         * @param dt The delta time
         */
        void update(float dt);

        /**
         * @brief Function to set the camera entity.
         *
         * This function is used to set the camera entity for the scene.
         * @param entity The entity representing the camera.
         */
        void setCameraEntity(Entity entity);

        /**
         * @brief Function to get the camera entity.
         *
         * This function is used to get the camera entity for the scene.
         * @return The entity representing the camera.
         */
        Entity getCameraEntity() const;

        /**
         * @brief Function to get the scene.
         *
         * This function is used to get the scene that contains the ECS.
         * @return The scene that contains the ECS.
         */
        void *getScene() const;

        /**
         * @brief Function to set the scene.
         *
         * This function is used to set the scene that contains the ECS.
         * @param scene The scene that contains the ECS.
         */
        void setScene(void *scene);

        /**
         * @brief Get a system
         *
         * This function will be used to get a system
         *
         * @tparam T The system to get
         * @return std::shared_ptr<T> The system
         */
        template <typename T>
        std::shared_ptr<T> getSystem()
        {
            return _systemManager->getSystem<T>();
        }

    private:
        std::unique_ptr<LE::ComponentManager> _componentManager; ///< The component manager
        std::unique_ptr<LE::EntityManager> _entityManager;       ///< The entity manager
        std::unique_ptr<LE::SystemManager> _systemManager;       ///< The system manager
        Entity _cameraEntity;                                    ///< The entity representing the camera
        void *_scene;                                            ///< The scene that contains the ECS
    };
}
