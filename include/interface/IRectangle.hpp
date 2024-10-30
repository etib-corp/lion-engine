/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IRectangle
*/

#ifndef IRECTANGLE_HPP_
#define IRECTANGLE_HPP_

#include "IShape.hpp"
#include "Maths/Vector2.hpp"

namespace LE
{
    /**
     * @class IRectangle
     * @brief Interface for rectangle shapes.
     *
     * The IRectangle interface provides a way to create rectangle shapes.
     */
    class IRectangle : public IShape
    {
    public:
        /**
         * @brief Construct a new IRectangle object
         */
        virtual ~IRectangle() = default;

        /**
         * @brief Set the size of the rectangle.
         *
         * @param size The size of the rectangle.
         * @return void
         */
        virtual void setSize(const LE::Vector2<float> &size);

        /**
         * @brief Get the size of the rectangle.
         *
         * @return The size of the rectangle.
         */
        virtual void init() = 0;

        /**
         * @brief Get the size of the rectangle.
         *
         * @return The size of the rectangle.
         */
        virtual LE::Vector2<float> getSize() const;

    protected:
        LE::Vector2<float> _size; /*!< The size of the rectangle */
    };
}

#endif /* !IRECTANGLE_HPP_ */
