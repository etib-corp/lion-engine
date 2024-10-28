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

namespace LE {
    class SFMLRectangle : public IRectangle {
        public:
            SFMLRectangle(const LE::Vector3<float>& position, const LE::Vector2<float>& size, LE::IColor *color);

            ~SFMLRectangle();

            void setPosition(const LE::Vector3<float>& position) override;

            void move(const LE::Vector3<float>& moveVector) override;

            void init() override;

        protected:
            sf::RectangleShape *_rectangle;
    };
}

#endif /* !SFMLRECTANGLE_HPP_ */
