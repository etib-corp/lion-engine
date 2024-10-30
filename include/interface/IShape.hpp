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

namespace LE
{
    /**
     * @class IShape
     * @brief Interface for shapes.
     *
     * The IShape interface provides a way to create shapes.
     */
    class IShape
    {
    public:
        /**
         * @brief Construct a new IShape object
         */
        virtual ~IShape() = default;

        /**
         * @brief Set the position of the shape.
         *
         * @param position The position of the shape.
         * @return void
         */
        virtual void setPosition(const LE::Vector3<float> &position);

        /**
         * @brief Set the color of the shape.
         *
         * @param color The color of the shape.
         * @return void
         */
        virtual void setColor(LE::Color *color);

        /**
         * @brief Move the shape.
         *
         * @param moveVector The vector to move the shape by.
         * @return void
         */
        virtual void move(const LE::Vector3<float> &moveVector);

        /**
         * @brief Initialize the shape.
         *
         * @return void
         */
        virtual void init() = 0;

        /**
         * @brief Get the position of the shape.
         *
         * @return The position of the shape.
         */
        virtual LE::Vector3<float> getPosition() const;

        /**
         * @brief Get the color of the shape.
         *
         * @return The color of the shape.
         */
        virtual LE::Color *getColor() const;

    protected:
        LE::Vector3<float> _position; /*!< The position of the shape */
        LE::Color *_color;            /*!< The color of the shape */
    };
}

#endif /* !ISHAPE_HPP_ */
