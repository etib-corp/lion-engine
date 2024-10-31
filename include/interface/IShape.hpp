/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IShape
*/

#ifndef ISHAPE_HPP_
#define ISHAPE_HPP_

#include "Maths/Vector3.hpp"
#include "Color.hpp"

namespace LE {
    /**
     * @brief The IShape interface
     *
     * This class is an interface that is used to create a shape object by inheriting from it.
     *
     * The shape is represented by 2 values: position and color.
     * The position is a `LE::Vector3<float>` that contains the `x`, `y` and `z` coordinates of the shape. (z if your are in a 3D environment like OpenGL)
     * The color is a `LE::Color` that contains the `red`, `green`, `blue` and `alpha` values of the shape.
     *
     *
     * @example
     * @code
     * LE::IShape shape;
     * shape.setPosition({42, 42, 42});
     * shape.setColor(new LE::Color(255, 0, 0, 255));
     * @endcode
     *
     */
    class IShape {
        public:
            /**
             * @brief Default destructor.
             */
            virtual ~IShape() = default;

            /**
             * @brief Set the position of the shape
             *
             * @param position The position of the shape
             * @return void
             *
            */
            virtual void setPosition(const LE::Vector3<float>& position);

            /**
             * @brief Set the color of the shape
             *
             * @param color The color of the shape
             * @return void
             *
            */
            virtual void setColor(LE::Color *color);

            /**
             * @brief Move the shape
             *
             * @param moveVector The vector to move the shape
             * @return void
             */
            virtual void move(const LE::Vector3<float>& moveVector);

            /**
             * @brief Initialize the shape
             *
             * @return void
             *
            */
            virtual void init() = 0;

            /**
             * @brief Draw the shape
             *
             * @return void
             *
            */
            virtual void draw() = 0;

            /**
             * @brief Get the position of the shape
             *
             * @return LE::Vector3<float>
             *
            */
            virtual LE::Vector3<float> getPosition() const;

            /**
             * @brief Get the color of the shape
             *
             * @return LE::Color
             *
            */
            virtual LE::Color *getColor() const;

            virtual void resize(float width, float height) = 0;

        protected:
            LE::Vector3<float> _position;   /*!< The position of the shape */
            LE::Color *_color;              /*!< The color of the shape */
    };
}

#endif /* !ISHAPE_HPP_ */
