/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include <iostream>


/**
 * @namespace LE
 * @brief The namespace for the Lion Engine.
 */

namespace LE {
    /**
     * @class IWindow
     * @brief Interface for a window in the Lion Engine.
     *
     * This class provides an interface for window operations such as checking if the window is open,
     * closing the window, clearing the window, displaying the window, and getting/setting the window title.
     *
     * @note This is an abstract class and cannot be instantiated directly.
     */
    class IWindow {
        public:
            virtual ~IWindow() = default;

            /**
             * @brief Checks if the window is currently open.
             *
             * @return true if the window is open, false otherwise.
             */
            virtual bool isOpen() { return _isOpen; }

            /**
             * @brief Closes the window.
             */
            virtual void close() { _isOpen = false; }

            /**
             * @brief Clears the window.
             */
            virtual void clear() = 0;

            /**
             * @brief Displays the window.
             */
            virtual void display() = 0;

            /**
             * @brief Gets the width of the window.
             *
             * @return The width of the window.
             */
            virtual std::string getTitle() { return _title; }

            /**
             * @brief Gets the height of the window.
             *
             * @return The height of the window.
             */
            virtual void setTitle(const std::string& title) { _title = title; }

        protected:
            const unsigned int _width;          ///< The width of the window.
            const unsigned int _height;         ///< The height of the window.
            std::string _title;                 ///< The title of the window.
            bool _isOpen;                       ///< Whether the window is open or not.
        private:
    };
}

#endif /* !IWINDOW_HPP_ */
