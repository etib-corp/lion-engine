/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLSpriteComponent
*/

#pragma once

#include "interface/ISpriteComponent.hpp"
#include "SFMLCommon.hpp"
#include "SFMLWindow.hpp"
#include <memory>

namespace LE {
    class SFMLSpriteComponent : public ISpriteComponent {
        public:
            SFMLSpriteComponent() = default;
            ~SFMLSpriteComponent() = default;

            std::shared_ptr<sf::Texture> texture;
            std::shared_ptr<sf::Sprite> sprite;
            std::shared_ptr<SFMLWindow> window;
    };

    namespace Sprite {
        std::shared_ptr<LE::ISpriteComponent> createSpriteComponent(const std::string& path, std::shared_ptr<LE::IWindow> window);
        void drawSpriteComponent(std::shared_ptr<LE::ISpriteComponent> sprite);
    }
}
