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

namespace LE {
    /**
     * @brief The IRectangle class
     *
     * This class is an interface that is used to create a rectangle object by inheriting from it.
     *
     * The rectangle is represented by 1 value: size.
     * The size is a `LE::Vector2<float>` that contains the `width` and the `height` of the rectangle.
     *
     *
     * @example
     * @code
     * LE::IRectangle rectangle;
     * rectangle.setSize({42, 42});
     * @endcode
     *
     */
    class IRectangle : public IShape {
        public:
            /**
             * @brief Default destructor.
            */
            virtual ~IRectangle() = default;

            /**
             * @brief Set the size of the rectangle
             *
             * @param size The size of the rectangle
             * @return void
             *
            */
            virtual void setSize(const LE::Vector2<float>& size);

            /**
             * @brief Get the size of the rectangle
             *
             * @return LE::Vector2<float>
             *
            */
            virtual void init() = 0;

            /**
             * @brief Get the size of the rectangle
             *
             * @return LE::Vector2<float>
             *
            */
            virtual LE::Vector2<float> getSize() const;

        protected:
            LE::Vector2<float> _size;   /*!< The size of the rectangle */
    };
}

#endif /* !IRECTANGLE_HPP_ */
