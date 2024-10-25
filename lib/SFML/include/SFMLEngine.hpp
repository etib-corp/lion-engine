/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEngine
*/

#pragma once

#include "IEngine.hpp"
#include "SFMLCommon.hpp"
#include "SFMLFont.hpp"
#include "SFMLShader.hpp"
#include "SFMLSpriteComponent.hpp"
#include "SFMLWindow.hpp"

namespace LE {
    class SFMLEngine : public LE::IEngine {
        public:
            SFMLEngine() = default;
            ~SFMLEngine() = default;

            std::shared_ptr<LE::IFont> createFont(const std::string& path, int height, int width) override
            {

            }

            std::shared_ptr<LE::IShader> createShader(const std::string& vertexPath, const std::string& fragmentPath) override
            {
            }

            std::shared_ptr<LE::IWindow> createWindow(int width, int height, const std::string& title) override
            {
                _window = std::make_shared<LE::SFMLWindow>(width, height, title);

                return _window;
            }

            std::shared_ptr<LE::ISpriteComponent> createSpriteComponent(const std::string& path) override
            {
                if (!_window) {
                    throw LE::IEngineError("");
                }
                std::shared_ptr<LE::SFMLSpriteComponent> sprite =  std::make_shared<LE::SFMLSpriteComponent>(path);
            }
    };
}