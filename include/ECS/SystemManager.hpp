/*
** EPITECH PROJECT, 2024
** client
** File description:
** SystemManager
*/

#pragma once

#include "ECS/common.hpp"

namespace LE
{
    class Ecs;
}

/**
 * @class System
 * @brief The System class is the base
 */
class System
{
public:
    /**
     * @brief Update the system
     * This function will be used to update the system
     */
    virtual void update(LE::Ecs *ecs, float dt) = 0;

    std::set<Entity> _entities; ///< The entities that the system is responsible for
};

/**
 * @class SystemManagerError
 * @brief SystemManagerError class
 * This class is used to throw errors related to the SystemManager
 */
class SystemManagerError : public LE::IError
{
public:
    /**
     * @brief Construct a new SystemManagerError object
     * @param title The message to display
     * @param details The details of the error
     * @param help The help message
     */
    SystemManagerError(const std::string &title, const std::string &details, const std::string &help) : LE::IError(title, details, help) {}
};

namespace LE
{
    /**
     * @class SystemManager
     * @brief The SystemManager class is responsible for registering systems and entities
     * The SystemManager class is responsible for registering systems and entities
     */
    class SystemManager
    {
    public:
        /**
         * @brief Register a system
         * This function will be used to register a system
         *
         * @tparam T The system to register
         * @return std::shared_ptr<T> The system that was registered
         */
        template <typename T>
        std::shared_ptr<T> registerSystem()
        {
            std::string typeName = typeid(T).name();

            if (_systems.find(typeName) != _systems.end())
            {
                throw SystemManagerError("System already registered", "The system is already registered", "Try to register a different system");
            }

            auto system = std::make_shared<T>();
            _systems.insert({typeName, system});
            return system;
        }

        /**
         * @brief Set the signature of a system
         * This function will be used to set the signature of a system
         *
         * @tparam T The system to set the signature of
         * @param signature The signature to set
         */
        template <typename T>
        void setSignature(Signature signature)
        {
            std::string typeName = typeid(T).name();

            if (_systems.find(typeName) == _systems.end())
            {
                throw SystemManagerError("System not registered before setting signature", "The system is not registered", "Try to register the system before setting the signature");
            }

            _signatures.insert({typeName, signature});
        }

        /**
         * @brief Entity destroyed
         * This function will be used to destroy an entity
         *
         * @param entity The entity to destroy
         */
        void entityDestroyed(Entity entity)
        {
            for (auto const &pair : _systems)
            {
                auto const &system = pair.second;

                system->_entities.erase(entity);
            }
        }

        /**
         * @brief Entity signature changed
         * This function will be used to change the signature of an entity
         *
         * @param entity The entity to change the signature of
         * @param entitySignature The signature to change to
         */
        void entitySignatureChanged(Entity entity, Signature entitySignature)
        {
            for (auto const &pair : _systems)
            {
                auto const &type = pair.first;
                auto const &system = pair.second;
                auto const &systemSignature = _signatures[type];

                if ((entitySignature & systemSignature) == systemSignature)
                {
                    system->_entities.insert(entity);
                }
                else
                {
                    system->_entities.erase(entity);
                }
            }
        }

        /**
         * @brief Delete a system
         *
         * This function will be used to delete a system
         */
        template <typename T>
        void deleteSystem()
        {
            std::string typeName = typeid(T).name();

            if (_systems.find(typeName) == _systems.end())
            {
                throw SystemManagerError("System not registered before deleting", "The system is not registered", "Try to register the system before deleting");
            }

            _systems.erase(typeName);
        }

        /**
         * @brief Update the systems
         *
         * This function will be used to update the systems
         */
        void update(Ecs *ecs, float dt)
        {
            for (auto const &pair : _systems)
            {
                auto const &system = pair.second;

                system->update(ecs, dt);
            }
        }

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
            std::string typeName = typeid(T).name();

            if (_systems.find(typeName) == _systems.end())
            {
                throw SystemManagerError("System not registered before getting", "The system is not registered", "Try to register the system before getting");
            }

            return std::dynamic_pointer_cast<T>(_systems[typeName]);
        }

    private:
        std::unordered_map<std::string, Signature> _signatures;            ///< Map of signatures
        std::unordered_map<std::string, std::shared_ptr<System>> _systems; ///< Map of systems
    };
}
