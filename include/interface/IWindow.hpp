/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include <iostream>

#include "Scene.hpp"

/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */

namespace LE
{
    /**
     * @class IWindow
     * @brief Interface for a window in the Lion Engine.
     *
     * This class provides an interface for window operations such as checking if the window is open,
     * closing the window, clearing the window, displaying the window, and getting/setting the window title.
     *
     * @note This is an abstract class and cannot be instantiated directly.
     */
    class IWindow
    {
    public:
        virtual ~IWindow() = default;

        /**
         * @brief Checks if the window is currently open.
         *
         * @return true if the window is open, false otherwise.
         */
        virtual bool isOpen() = 0;

        /**
         * @brief Closes the window.
         */
        virtual void close() = 0;

        /**
         * @brief Clears the window.
         */
        virtual void clear() = 0;

        /**
         * @brief Displays the window.
         */
        virtual void display() = 0;

        /**
         * @brief Renders the scene to the window.
         *
         * @param scene The scene to render.
         */
        virtual void render(std::shared_ptr<LE::Scene> scene) = 0;

        /**
         * @brief Gets the title of the window.
         *
         * @return The title of the window.
         */
        virtual const std::string &getTitle()
        {
            return _title;
        }

        /**
         * @brief Sets the title of the window.
         *
         * @param title The new title of the window.
         */
        virtual void setTitle(const std::string &title) = 0;

        /**
         * @brief Gets the width of the window.
         *
         * @return The width of the window.
         */
        virtual unsigned int getWidth()
        {
            return _width;
        }

        /**
         * @brief Gets the height of the window.
         *
         * @return The height of the window.
         */
        virtual unsigned int getHeight()
        {
            return _height;
        }

    protected:
        unsigned int _width;  ///< The width of the window.
        unsigned int _height; ///< The height of the window.
        std::string _title;   ///< The title of the window.
    private:
    };
}

#endif /* !IWINDOW_HPP_ */
