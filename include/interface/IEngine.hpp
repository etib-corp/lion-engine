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

    #include "interface/IError.hpp"
    #include "interface/IFont.hpp"
    #include "interface/IShader.hpp"
    #include "interface/ISpriteComponent.hpp"
    #include "interface/IWindow.hpp"

/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */
namespace LE {
    class IEngineError : public IError {
        public:
            IEngineError(const std::string &message) : IError(message) {}
            ~IEngineError() = default;
    };

    /**
     * @class IEngine
     * @brief Interface for the Lion Engine core functionalities.
     *
     * The IEngine interface provides methods to create various engine components such as fonts, shaders, and windows.
     */
    class IEngine {
        public:
            virtual ~IEngine() = default;

            /**
             * @brief Creates a font resource.
             *
             * @param path The file path to the font resource.
             * @param height The height of the font.
             * @param width The width of the font.
             * @return A shared pointer to the created font resource.
             */
            virtual std::shared_ptr<LE::IFont> createFont(const std::string& path, int height, int width) = 0;

            /**
             * @brief Creates a shader resource.
             *
             * @param vertexPath The file path to the vertex shader.
             * @param fragmentPath The file path to the fragment shader.
             * @return A shared pointer to the created shader resource.
             */
            virtual std::shared_ptr<LE::IShader> createShader(const std::string& vertexPath, const std::string& fragmentPath) = 0;

            /**
             * @brief Creates a window.
             *
             * @param width The width of the window.
             * @param height The height of the window.
             * @param title The title of the window.
             * @return A shared pointer to the created window.
             */
            virtual std::shared_ptr<LE::IWindow> createWindow(int width, int height, const std::string& title) = 0;

            /**
             * @brief Creates a sprite component.
             *
             * @param texturePath The file path to the texture.
             * @return A shared pointer to the created sprite component.
             */
            virtual std::shared_ptr<LE::ISpriteComponent> createSpriteComponent(const std::string& texturePath) = 0;

        protected:
            std::shared_ptr<IWindow> _window;
            std::map<std::string, std::shared_ptr<ISpriteComponent>> _sprites;

        private:
    };
}

#endif /* !IENGINE_HPP_ */
