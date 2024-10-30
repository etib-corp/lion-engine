/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLCameraComponent
*/

#include "SFMLCameraComponent.hpp"

std::shared_ptr<LE::ICameraComponent> LE::Camera::createCameraComponent(const LE::Vector2<float>& position, const LE::Vector2<float>& size, std::shared_ptr<LE::IWindow> window)
{
    auto camera = std::make_shared<LE::SFMLCameraComponent>();
    camera->view = std::make_shared<sf::View>(sf::Vector2f(position.x, position.y), sf::Vector2f(size.x, size.y));
    camera->window = std::dynamic_pointer_cast<LE::SFMLWindow>(window);
    return camera;
}