/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IEngine
*/

#ifndef IENGINE_HPP_
#define IENGINE_HPP_

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "interface/IError.hpp"
#include "interface/IEventManager.hpp"
#include "interface/IFont.hpp"
#include "interface/IShader.hpp"
#include "interface/ISpriteComponent.hpp"
#include "interface/ICameraComponent.hpp"
#include "interface/GUI/IText.hpp"
#include "interface/IWindow.hpp"
#include "ECS/Systems/IRender2DSystem.hpp"
#include "SceneManager.hpp"
#include "interface/IGame.hpp"
#include "Clock.hpp"
#include "interface/IGame.hpp"
#include "NetworkLoaderLib.hpp"

/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */
namespace LE
{
    class IEngineError : public IError
    {
    public:
        IEngineError(const std::string &title = "", const std::string &details = "", const std::string &help = "") : IError(title, details, help) {}
        ~IEngineError() = default;
    };

    /**
     * @class IEngine
     * @brief Interface for the Lion Engine core functionalities.
     *
     * The IEngine interface provides methods to create various engine components such as fonts, shaders, and windows.
     */
    class IEngine
    {
    public:
        virtual ~IEngine() = default;

        /**
         * @brief Initializes the engine.
         *
         */
        virtual void init();

        /**
         * @brief Creates a font resource.
         *
         * @param path The file path to the font resource.
         * @param height The height of the font.
         * @param width The width of the font.
         * @return A shared pointer to the created font resource.
         */
        virtual std::shared_ptr<LE::IFont> createFont(const std::string &path, int height, int width) = 0;

        /**
         * @brief Creates a shader resource.
         *
         * @param vertexPath The file path to the vertex shader.
         * @param fragmentPath The file path to the fragment shader.
         * @return A shared pointer to the created shader resource.
         */
        virtual std::shared_ptr<LE::IShader> createShader(const std::string &vertexPath, const std::string &fragmentPath) = 0;

        /**
         * @brief Creates a window.
         *
         * @param width The width of the window.
         * @param height The height of the window.
         * @param title The title of the window.
         * @return A shared pointer to the created window.
         */
        virtual std::shared_ptr<LE::IWindow> createWindow(int width, int height, const std::string &title) = 0;

        /**
         * @brief Creates a sprite component.
         *
         * @param texturePath The file path to the texture.
         * @return A shared pointer to the created sprite component.
         */
        virtual std::shared_ptr<LE::ISpriteComponent> createSpriteComponent(const std::string &texturePath) = 0;

        /**
         * @brief Creates a camera component.
         *
         * @return A shared pointer to the created camera component.
         */
        virtual std::shared_ptr<LE::ICameraComponent> createCameraComponent(const LE::Vector2<float> &position, const LE::Vector2<float> &size) = 0;

        /**
         * @brief Creates Event Manager.
         *
         *  @return A shared pointer to the created Event Manager.
         */
        virtual std::shared_ptr<LE::IEventManager> createEventManager() = 0;

        /**
         * @brief Get the window.
         *
         * @return A shared pointer to the window.
         */
        template <typename T>
        std::shared_ptr<T> getWindow()
        {
            return std::dynamic_pointer_cast<T>(_window);
        }

        virtual std::shared_ptr<IRender2DSystem> createRender2DSystem(LE::Ecs &ecs) = 0;

        virtual std::shared_ptr<SceneManager> createSceneManager()
        {
            return std::make_shared<SceneManager>(*this);
        }

        /**
         * @brief Runs the engine.
         *
         * @param throwError A boolean flag indicating whether to throw an error.
         */
        void run(bool throwError = false);

        /**
         * @brief Outputs debug information.
         *
         * @param message The debug message to output.
         */
        void debug(const std::string &message);

        /**
         * @brief Sets the game.
         *
         * @tparam T The class of the game to set.
         */
        template <typename T>
        void setGame()
        {
            _game = std::make_shared<T>();
            _game->init(*this);
        }

        /**
         * @brief Gets the game.
         *
         * @return A shared pointer to the game.
         */
        std::shared_ptr<LE::IGame> getGame();

        /**
         * @brief Adds a scene to the game.
         *
         * @tparam T The class of the scene to add.
         */
        template <typename T>
        std::shared_ptr<T> addScene(const std::string &name)
        {
            auto scene = std::make_shared<T>(this);
            scene->init();
            _game->getSceneManager()->addScene(scene, name);
            return scene;
        }

        void playScene(const std::string &name)
        {
            _game->getSceneManager()->play(name);
        }

        /**
         * @brief Throws an error.
         *
         * @param error The error to throw.
         * @note This function is use to throw an error from the Engine class only if the throwError flag is set to true.
         */
        void throwError(const LE::Error &error);

        /**
         * @brief Sets the configuration function.
         *
         * This function is used to set a configuration function that will be called before the engine starts running.
         *
         * @param func The configuration function to set.
         */
        void setConfig(std::function<void()> func);

        /**
         * @brief Sets the loop function.
         *
         * This function is used to set a loop function that will be called during the engine's main loop.
         *
         * @param func The loop function to set.
         */
        void setLoop(std::function<void()> func);

        /**
         * @brief Sets the frame rate limit for the window.
         *
         * @param limit The frame rate limit.
         */
        void setFramerateLimit(std::size_t limit);

        /**
         * @brief Gets the width of the window.
         *
         * @return The width of the window.
         */
        std::size_t getWindowWidth() const;

        /**
         * @brief Gets the height of the window.
         *
         * @return The height of the window.
         */
        std::size_t getWindowHeight() const;

        float getDeltaTime() const;

        void restartClock();

        std::unique_ptr<NetworkLoaderLib> &getNetworkLoaderLib();

        INetworkModule *getNetworkModule();

    protected:
        std::shared_ptr<IWindow> _window;
        std::map<std::string, std::shared_ptr<ISpriteComponent>> _sprites;
        std::map<std::string, std::shared_ptr<IFont>> _fonts;
        std::vector<std::shared_ptr<ICameraComponent>> _cameras;
        std::shared_ptr<IEventManager> _eventManager;
        std::shared_ptr<IGame> _game;
        std::function<void()> _configFunc;                   ///< Configuration function. This function is called before the engine starts running.
        std::function<void()> _loopFunc;                     ///< Loop function. This function is called during the engine's main loop.
        std::unique_ptr<NetworkLoaderLib> _networkLoaderLib; ///< Unique pointer to the NetworkLoaderLib object.
        INetworkModule *_networkModule;                      ///< Unique pointer to the NetworkModule object.
        std::unique_ptr<LE::Clock> _clock;                   ///< Unique pointer to the Clock object.
        float _dt;                                           ///< The delta time.
        std::size_t _framerateLimit;                         ///< The frame rate limit.
        bool _throwError;                                    ///< A boolean flag indicating whether to throw an error.
    private:
    };
}

extern std::shared_ptr<LE::IEngine> g_engine;

#endif /* !IENGINE_HPP_ */
