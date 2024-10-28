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
    class IRectangle : public IShape {
        public:
            virtual ~IRectangle() = default;

            virtual void setSize(const LE::Vector2<float>& size);

            virtual void init() = 0;

            virtual LE::Vector2<float> getSize() const;

        protected:
            LE::Vector2<float> _size;
    };
}

#endif /* !IRECTANGLE_HPP_ */
