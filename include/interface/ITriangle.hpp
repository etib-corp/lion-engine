/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ITriangle
*/

#ifndef ITRIANGLE_HPP_
#define ITRIANGLE_HPP_

#include "IShape.hpp"

namespace LE {
    /**
     * @brief The ITriangle interface
     *
     * This class is an interface that is used to create a triangle object by inheriting from it.
     *
     * The triangle is represented by 3 values: point1, point2 and point3.
     * Each value is a `LE::Vector3<float>` that contains the `x`, `y` and `z` coordinates of the triangle. (z if your are in a 3D environment like OpenGL)
     *
     *
     * @example
     * @code
     * LE::ITriangle triangle;
     * triangle.setPoint1({42, 42, 42});
     * triangle.setPoint2({42, 42, 42});
     * triangle.setPoint3({42, 42, 42});
     * @endcode
     *
     */
    class ITriangle : public IShape {
        public:
            /**
             * @brief Default destructor.
             */
            virtual ~ITriangle() = default;

            /**
             * @brief Set the first point of the triangle
             *
             * @param point1 The first point of the triangle
             * @return void
             *
            */
            virtual void setPoint1(const LE::Vector3<float>& point1);

            /**
             * @brief Set the second point of the triangle
             *
             * @param point2 The second point of the triangle
             * @return void
             *
            */
            virtual void setPoint2(const LE::Vector3<float>& point2);

            /**
             * @brief Set the third point of the triangle
             *
             * @param point3 The third point of the triangle
             * @return void
             *
            */
            virtual void setPoint3(const LE::Vector3<float>& point3);

            /**
             * @brief Move the triangle
             *
             * @param moveVector The vector to move the triangle
             * @return void
             */
            void move(const LE::Vector3<float>& moveVector) override;

            /**
             * @brief Initialize the triangle
             *
             * @return void
             *
            */
            virtual void init() = 0;

            /**
             * @brief Get the first point of the triangle
             *
             * @return LE::Vector3<float>
             *
            */
            LE::Vector3<float> getPoint1() const;

            /**
             * @brief Get the second point of the triangle
             *
             * @return LE::Vector3<float>
             *
            */
            LE::Vector3<float> getPoint2() const;

            /**
             * @brief Get the third point of the triangle
             *
             * @return LE::Vector3<float>
             *
            */
            LE::Vector3<float> getPoint3() const;


        protected:
            LE::Vector3<float> _point1; /*!< The first point of the triangle */
            LE::Vector3<float> _point2; /*!< The second point of the triangle */
            LE::Vector3<float> _point3; /*!< The third point of the triangle */
    };
}

#endif /* !ITRIANGLE_HPP_ */
