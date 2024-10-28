/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEngine
*/

#pragma once

#include "interface/IEngine.hpp"
#include "SFMLCommon.hpp"
#include "SFMLFont.hpp"
#include "SFMLShader.hpp"
#include "SFMLSpriteComponent.hpp"
#include "SFMLWindow.hpp"

/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */
namespace LE {

    /**
     * @brief Creates an instance of the SFMLEngine class.
     *
     * @return A shared pointer to the created SFMLEngine instance.
     */

    /**
     * @class SFMLEngine
     * @brief The SFMLEngine class is an implementation of the IEngine interface using the SFML library.
     *
     * The SFMLEngine class provides methods to create various engine components such as fonts, shaders, and windows using the SFML library.
     */
    class SFMLEngine : public LE::IEngine {
        public:
            /**
             * @brief Default constructor for the SFMLEngine class.
             */
            SFMLEngine() = default;

            /**
             * @brief Default destructor for the SFMLEngine class.
             */
            ~SFMLEngine() = default;

            std::shared_ptr<LE::IFont> createFont(const std::string& path, int height, int width) override
            {
                std::shared_ptr<LE::IFont> font = std::make_shared<LE::SFMLFont>(path, height, width);
                font->init();
                _fonts[path] = font;
                return font;
            }

            std::shared_ptr<LE::IShader> createShader(const std::string& vertexPath, const std::string& fragmentPath) override
            {
                return nullptr;
            }

            std::shared_ptr<LE::IWindow> createWindow(int width, int height, const std::string& title) override
            {
                _window = std::make_shared<LE::SFMLWindow>(width, height, title);
                return _window;
            }

            std::shared_ptr<LE::ISpriteComponent> createSpriteComponent(const std::string& path) override
            {
                if (!_window) {
                    throw LE::IEngineError("No window was created.", "You must create a window before creating a sprite component.", "Try creating a window first.");
                }
                auto iSprite = LE::Sprite::createSpriteComponent(path, _window);
                std::shared_ptr<LE::SFMLSpriteComponent> sprite = std::dynamic_pointer_cast<LE::SFMLSpriteComponent>(iSprite);
                sprite->window = std::dynamic_pointer_cast<LE::SFMLWindow>(_window);
                _sprites[path] = sprite;
                return sprite;
            }
    };
}
