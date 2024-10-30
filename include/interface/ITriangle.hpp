/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ITriangle
*/

#ifndef ITRIANGLE_HPP_
#define ITRIANGLE_HPP_

#include "IShape.hpp"

namespace LE
{
    /**
     * @class ITriangle
     * @brief Interface for triangle shapes.
     *
     * The ITriangle interface provides a way to create triangle shapes.
     */
    class ITriangle : public IShape
    {
    public:
        /**
         * @brief Construct a new ITriangle object
         */
        virtual ~ITriangle() = default;

        /**
         * @brief Set the first point of the triangle.
         *
         * @param point1 The first point of the triangle.
         * @return void
         */
        virtual void setPoint1(const LE::Vector3<float> &point1);

        /**
         * @brief Set the second point of the triangle.
         *
         * @param point2 The second point of the triangle.
         * @return void
         */
        virtual void setPoint2(const LE::Vector3<float> &point2);

        /**
         * @brief Set the third point of the triangle.
         *
         * @param point3 The third point of the triangle.
         * @return void
         */
        virtual void setPoint3(const LE::Vector3<float> &point3);

        /**
         * @brief Get the first point of the triangle.
         *
         * @return The first point of the triangle.
         */
        void move(const LE::Vector3<float> &moveVector) override;

        /**
         * @brief Initialize the triangle.
         *
         * @return void
         */
        virtual void init() = 0;

        /**
         * @brief Get the first point of the triangle.
         *
         * @return The first point of the triangle.
         */
        LE::Vector3<float> getPoint1() const;

        /**
         * @brief Get the second point of the triangle.
         *
         * @return The second point of the triangle.
         */
        LE::Vector3<float> getPoint2() const;

        /**
         * @brief Get the third point of the triangle.
         *
         * @return The third point of the triangle.
         */
        LE::Vector3<float> getPoint3() const;

    protected:
        LE::Vector3<float> _point1; /*!< The first point of the triangle */
        LE::Vector3<float> _point2; /*!< The second point of the triangle */
        LE::Vector3<float> _point3; /*!< The third point of the triangle */
    };
}

#endif /* !ITRIANGLE_HPP_ */
