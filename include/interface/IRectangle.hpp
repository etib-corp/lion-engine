/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IRectangle
*/

#ifndef IRECTANGLE_HPP_
    #define IRECTANGLE_HPP_

    #include "Maths/Vector3.hpp"
    #include "Maths/Vector2.hpp"
    #include "IColor.hpp"

namespace LE {
    class IRectangle {
        public:
            virtual ~IRectangle() = default;

            virtual void setPosition(const LE::Vector3<float>& position);

            virtual void setSize(const LE::Vector2<float>& size);

            virtual void setColor(LE::IColor *color);

            virtual void move(const LE::Vector3<float>& moveVector);

            virtual void init() = 0;

            virtual LE::Vector3<float> getPosition() const;

            virtual LE::Vector2<float> getSize() const;

            virtual LE::IColor *getColor() const;

        protected:
            LE::Vector3<float> _position;
            LE::Vector2<float> _size;
            LE::IColor *_color;
    };
}

#endif /* !IRECTANGLE_HPP_ */
