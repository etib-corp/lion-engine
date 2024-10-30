/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLRectangle
*/

#ifndef SFMLRECTANGLE_HPP_
    #define SFMLRECTANGLE_HPP_

    #include "IRectangle.hpp"
    #include "SFMLCommon.hpp"
    #include "SFMLWindow.hpp"

namespace LE {
    /**
     * @brief The SFMLRectangle class
     *
     * The SFMLRectangle class is a class that inherits from the IRectangle interface.
     *
     * It's used to draw a rectangle on the screen.
     *
    */
    class SFMLRectangle : public IRectangle {
        public:
            /**
             * @brief Construct a new SFMLRectangle object
             *
             * @param position The position of the rectangle
             * @param size The size of the rectangle
             * @param color The color of the rectangle
             */
            SFMLRectangle(const LE::Vector3<float>& position, const LE::Vector2<float>& size, LE::Color *color, std::shared_ptr<LE::IWindow> window);

            /**
             * @brief Destroy the SFMLRectangle object
             *
             */
            ~SFMLRectangle();

            /**
             * @brief Set the position of the rectangle
             *
             * @param position The position of the rectangle
             *
             * @return void
             */
            void setPosition(const LE::Vector3<float>& position) override;

            /**
             * @brief Move the rectangle by a vector.
             *
             * @param moveVector The vector to move the rectangle by
             *
             * @return void
             */
            void move(const LE::Vector3<float>& moveVector) override;

            /**
             * @brief Initialize the rectangle.
             *
             * @return void
             */
            void init() override;

            /**
             * @brief Draw the rectangle on the screen.
             *
             * @return void
             */
            void draw() override;

            std::shared_ptr<SFMLWindow> _window;    /*!< The window where the rectangle will be drawn*/
            sf::RectangleShape *_rectangle;         /*!< The rectangle shape interpreted in SFML*/
    };
}

#endif /* !SFMLRECTANGLE_HPP_ */
