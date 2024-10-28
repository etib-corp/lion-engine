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
    class SFMLTriangle : public LE::ITriangle {
        public:
            SFMLTriangle(const LE::Vector3<float> &point1, const LE::Vector3<float> &point2, const LE::Vector3<float> &point3);

            SFMLTriangle(const LE::Vector2<float> &point1, const LE::Vector2<float> &point2, const LE::Vector2<float> &point3);

            SFMLTriangle(const LE::Vector2<float> &pos, float size);
            ~SFMLTriangle();

            void init() override;

            void move(const LE::Vector3<float>& moveVector) override;

        protected:
            sf::ConvexShape *_triangle;

    };
}

#endif /* !SFMLTRIANGLE_HPP_ */
