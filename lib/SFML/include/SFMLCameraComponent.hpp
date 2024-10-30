/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLCameraComponent
*/

#pragma once

#include "interface/ICameraComponent.hpp"
#include "SFMLCommon.hpp"
#include "SFMLWindow.hpp"
#include <memory>

namespace LE {
    class SFMLCameraComponent : public ICameraComponent {
        public:
            SFMLCameraComponent() = default;
            ~SFMLCameraComponent() = default;

            std::shared_ptr<sf::View> view;
            std::shared_ptr<SFMLWindow> window;
    };

    namespace Camera {
        std::shared_ptr<LE::ICameraComponent> createCameraComponent(const LE::Vector2<float>& position, const LE::Vector2<float>& size, std::shared_ptr<LE::IWindow> window);
    }
}
