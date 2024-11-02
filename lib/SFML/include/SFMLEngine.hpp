/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEngine
*/

#pragma once

#include "interface/IEngine.hpp"

#include "ECS/Systems/SFMLRender2DSystem.hpp"
#include "ECS/Systems/SFMLCameraSystem.hpp"

#include "SFMLCameraComponent.hpp"
#include "SFMLCommon.hpp"
#include "SFMLFont.hpp"
#include "SFMLShader.hpp"
#include "SFMLSpriteComponent.hpp"
#include "SFMLWindow.hpp"
#include "SFMLEventManager.hpp"

#include "GUI/SFMLManager.hpp"
#include "GUI/SFMLButton.hpp"
#include "GUI/SFMLContainer.hpp"
#include "GUI/SFMLText.hpp"
#include "GUI/SFMLTextField.hpp"

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
                return sprite;
            }

            std::shared_ptr<LE::ISpriteComponent> createSpriteComponentFromMemory(const std::string& data) override
            {
                if (!_window) {
                    throw LE::IEngineError("No window was created.", "You must create a window before creating a sprite component.", "Try creating a window first.");
                }
                auto iSprite = LE::Sprite::createSpriteComponentFromMemory(data, _window);
                std::shared_ptr<LE::SFMLSpriteComponent> sprite = std::dynamic_pointer_cast<LE::SFMLSpriteComponent>(iSprite);
                sprite->window = std::dynamic_pointer_cast<LE::SFMLWindow>(_window);
                return sprite;
            }

            std::shared_ptr<LE::ICameraComponent> createCameraComponent(const LE::Vector2<float> &position, const LE::Vector2<float> &size) override
            {
                std::shared_ptr<LE::ICameraComponent> camera = LE::Camera::createCameraComponent(position, size, _window);
                _cameras.push_back(camera);
                return camera;
            }

            std::shared_ptr<LE::IEventManager> createEventManager() override
            {
                _eventManager = std::make_shared<LE::SFMLEventManager>(*this);
                return _eventManager;
            }

            std::shared_ptr<IRender2DSystem> createRender2DSystem(LE::Ecs &ecs) override
            {
                Signature signature;
                std::shared_ptr<SFMLRender2DSystem> render2DSystem = ecs.registerSystem<SFMLRender2DSystem>();
                render2DSystem->setEngine(this);
                signature.set(ecs.getComponentType<TransformComponent>());
                signature.set(ecs.getComponentType<std::shared_ptr<LE::ISpriteComponent>>());
                ecs.setSignature<SFMLRender2DSystem>(signature);
                return render2DSystem;
            }

            std::shared_ptr<ICameraSystem> createCameraSystem(LE::Ecs &ecs) override
            {
                Signature signature;
                std::shared_ptr<SFMLCameraSystem> cameraSystem = ecs.registerSystem<SFMLCameraSystem>();
                cameraSystem->setEngine(this);
                signature.set(ecs.getComponentType<TransformComponent>());
                signature.set(ecs.getComponentType<std::shared_ptr<LE::ICameraComponent>>());
                ecs.setSignature<SFMLCameraSystem>(signature);
                return cameraSystem;
            }

            std::shared_ptr<LE::GUI::IManager> createGUIManager(std::function<void(std::shared_ptr<LE::GUI::IManager>)> config) override
            {
                auto manager = std::make_shared<LE::GUI::SFMLManager>(_window);

                manager->init();
                config(manager);
                return manager;
            }

            std::shared_ptr<LE::GUI::IButton> createButton(std::function<void(std::shared_ptr<LE::GUI::IButton>)> config) override
            {
                std::shared_ptr<LE::GUI::SFMLButton> button = std::make_shared<LE::GUI::SFMLButton>(LE::Vector3<float>(0, 0, 0), LE::Vector2<float>(0, 0), "Hello", _window);

                button->init();
                config(button);
                return button;
            }

            std::shared_ptr<LE::GUI::IText> createText(std::function<void(std::shared_ptr<LE::GUI::IText>)> config) override
            {
                std::shared_ptr<LE::GUI::SFMLText> text = std::make_shared<LE::GUI::SFMLText>(LE::Vector3<float>(0, 0, 0), _window, "", nullptr);

                text->init();
                config(text);
                return text;
            }

            std::shared_ptr<LE::GUI::ITextField> createTextField(std::function<void(std::shared_ptr<LE::GUI::ITextField>)> config) override
            {
                auto textField = std::make_shared<LE::GUI::SFMLTextField>(LE::Vector3<float>(0, 0, 0), _window, "", "");

                textField->init();
                config(textField);
                return textField;
            }

            std::shared_ptr<LE::GUI::IContainer> createContainer(std::function<void(std::shared_ptr<LE::GUI::IContainer>)> config) override
            {
                auto container = std::make_shared<LE::GUI::SFMLContainer>(LE::Vector3<float>(0, 0, 0), LE::Vector2<float>(0, 0), _window);

                container->init();
                config(container);
                return container;
            }

            std::shared_ptr<LE::IRectangle> createRectangle(const LE::Vector3<float>& position, const LE::Vector2<float>& size, std::shared_ptr<LE::Color> color, std::shared_ptr<LE::IWindow> window)
            {
                auto rectangle = std::make_shared<LE::SFMLRectangle>(position, size, color, window);

                rectangle->init();
                return rectangle;
            }

    };
}
