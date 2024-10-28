/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_

    #include <iostream>

namespace LE {
    namespace GUI {
        class IComponent {
            public:
                virtual ~IComponent() = default;

                virtual void draw() = 0;

                size_t getId() const;

                virtual void init() = 0;

                void setPos(float x, float y);

                float getWidth() const;

                float getHeight() const;

                float getX() const;

                float getY() const;

            protected:
                size_t _id;
                float _x;
                float _y;
                float _width;
                float _height;
        };
    }
}

#endif /* !ICOMPONENT_HPP_ */
