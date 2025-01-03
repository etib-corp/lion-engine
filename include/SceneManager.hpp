/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

    #include "Scene.hpp"
    #include <unordered_map>
    #include <memory>
    #include <iostream>

namespace LE
{
       /**
     * @class SceneManager
     * @brief Manages scenes within the application.
     *
     * The SceneManager class is responsible for managing the lifecycle of scenes,
     * including playing, stopping, and switching between scenes. It maintains
     * a collection of scenes and tracks the current and previous scenes.
     *
     * @note This class uses the SceneManagerError custom exception class to handle
     * errors specific to scene management.
     *
     * @see SceneManagerError
     */
    class SceneManager {
        public:
            /**
             * @class SceneManagerError
             * @brief A custom exception class for handling errors specific to the SceneManager.
             *
             * This class inherits from the base Error class and is used to represent
             * errors that occur within the SceneManager. It provides a constructor
             * that accepts an error message.
             *
             * @see Error
             */
            class SceneManagerError : public LE::IError {
                public:
                    /**
                     * @brief Constructs a new SceneManagerError object.
                     *
                     * @param title The error message to be associated with this exception.
                     * @param details The details of the error.
                     * @param help The help message for the error.
                     */
                    SceneManagerError(const std::string &title, const std::string &details, const std::string &help) : IError(title, details, help) {}
            };

            /**
             * @brief Constructs a new SceneManager object.
             *
             * This constructor initializes the SceneManager, setting up any necessary
             * resources or configurations required for managing scenes within the application.
             */
            SceneManager(LE::IEngine &engine);

            /**
             * @brief Destructor for the SceneManager class.
             *
             * This destructor is responsible for cleaning up resources
             * and performing any necessary cleanup when a SceneManager
             * object is destroyed.
             */
            ~SceneManager();

            /**
             * @brief Starts playing the default scene.
             *
             * This method initiates the playback of the default scene configured in the scene manager.
             * It should be called when no specific scene needs to be specified.
             */
            void play();

            /**
             * @brief Starts playing the specified scene.
             *
             * This method initiates the playback of a scene identified by its name.
             * It should be called when a specific scene needs to be played.
             *
             * @param sceneName The name of the scene to play. This should match the name of a scene
             *                  that has been previously added to the scene manager.
             */
            void play(const std::string &sceneName);

            /**
             * @brief Stops the currently playing scene.
             *
             * This method halts the playback of the current scene. It should be called when the scene
             * needs to be stopped, either to switch to another scene or to end playback entirely.
             */
            void stop();

            /**
             * @brief Gets the current scene.
             *
             * @return A shared pointer to the currently playing scene.
             */
            std::shared_ptr<Scene> getCurrentScene() const;

            /**
             * @brief Gets the previous scene.
             *
             * @return A shared pointer to the previously played scene.
             */
            std::shared_ptr<Scene> getPreviousScene() const;

            /**
             * @brief Adds a new scene to the SceneManager.
             *
             * This method adds a new scene to the SceneManager, making it available for playback.
             * The scene is identified by a unique name, which can be used to reference the scene
             * when playing or stopping it.
             *
             * @param scene A shared pointer to the scene to add.
             * @param name The name to associate with the scene. This name should be unique
             *             and used to reference the scene when playing or stopping it.
             */
            void addScene(std::shared_ptr<Scene> scene, const std::string &name);

            /**
             * @brief Removes a scene from the SceneManager.
             *
             * This method removes a scene from the SceneManager, making it unavailable for playback.
             * The scene is identified by its name, which should match the name of the scene that was
             * previously added to the SceneManager.
             *
             * @param sceneName The name of the scene to remove.
             */
            void removeScene(const std::string &sceneName);

            /**
             * @brief Selects a scene to play.
             *
             * This method selects a scene to play based on its name. If the scene is not found
             * in the SceneManager, an exception is thrown.
             *
             * @param sceneName The name of the scene to play.
             */
            void selectScene(const std::string &sceneName);
        protected:
            LE::IEngine &_engine;
            std::unordered_map<std::string, std::shared_ptr<LE::Scene>> _scenes;
            std::string _currentSceneName;
            std::shared_ptr<LE::Scene> _currentScene;
            std::string _previousSceneName;
            std::shared_ptr<LE::Scene> _previousScene;
        private:
    };
} // namespace LE


#endif /* !SCENEMANAGER_HPP_ */
