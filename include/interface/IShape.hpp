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
    class IShape {
        public:
            virtual ~IShape() = default;

            virtual void setPosition(const LE::Vector3<float>& position);

            virtual void setColor(LE::Color *color);

            virtual void move(const LE::Vector3<float>& moveVector);

            virtual void init() = 0;

            virtual LE::Vector3<float> getPosition() const;

            virtual LE::Color *getColor() const;

        protected:
            LE::Vector3<float> _position;
            LE::Color *_color;
    };
}

#endif /* !ISHAPE_HPP_ */
