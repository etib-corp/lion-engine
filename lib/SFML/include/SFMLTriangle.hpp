/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLTriangle
*/

#ifndef SFMLTRIANGLE_HPP_
    #define SFMLTRIANGLE_HPP_

    #include "ITriangle.hpp"
    #include "SFMLCommon.hpp"

    #include "Maths/Vector2.hpp"

namespace LE {
    /**
     * @brief The SFMLTriangle class
     *
     * The SFMLTriangle class is a class that inherits from the ITriangle interface.
     *
     * It's used to draw a triangle on the screen.
     *
    */
    class SFMLTriangle : public LE::ITriangle {
        public:
            /**
             * @brief Construct a new SFMLTriangle object
             *
             * @param point1 The first point of the triangle
             * @param point2 The second point of the triangle
             * @param point3 The third point of the triangle
             */
            SFMLTriangle(const LE::Vector3<float> &point1, const LE::Vector3<float> &point2, const LE::Vector3<float> &point3);

            /**
             * @brief Construct a new SFMLTriangle object
             *
             * @param point1 The first point of the triangle
             * @param point2 The second point of the triangle
             * @param point3 The third point of the triangle
             */
            SFMLTriangle(const LE::Vector2<float> &point1, const LE::Vector2<float> &point2, const LE::Vector2<float> &point3);

            /**
             * @brief Construct a new SFMLTriangle object
             *
             * @param pos The position of the triangle
             * @param size The size of the triangle
             */
            SFMLTriangle(const LE::Vector2<float> &pos, float size);

            /**
             * @brief Destroy the SFMLTriangle object
             *
             */
            ~SFMLTriangle();

            /**
             * @brief Initialize the triangle.
             *
             * @return void
             */
            void init() override;

            /**
             * @brief Move the triangle by a vector.
             *
             * @param moveVector The vector to move the triangle by
             *
             * @return void
             */
            void move(const LE::Vector3<float>& moveVector) override;

        protected:
            sf::ConvexShape *_triangle;     /*!< The triangle shape interpreted in SFML*/

    };
}

#endif /* !SFMLTRIANGLE_HPP_ */
