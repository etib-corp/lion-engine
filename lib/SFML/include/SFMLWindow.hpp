/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLWindow
*/

#pragma once

#include "interface/IWindow.hpp"
#include "SFMLCommon.hpp"
#include <memory>

// ! the IWindow class is temporary

namespace LE {
    class SFMLWindow : public LE::IWindow {
        public:
            SFMLWindow(int width, int height, const std::string& title);
            ~SFMLWindow();

            bool isOpen() override;

            void close() override;

            void clear() override;

            void display() override;

            const std::string& getTitle() override;
            void setTitle(const std::string& title) override;

            unsigned int getWidth() override;

            unsigned int getHeight() override;

            const std::shared_ptr<sf::RenderWindow>& getWindow() const;
        private:
            std::shared_ptr<sf::RenderWindow> _window;
    };
}
