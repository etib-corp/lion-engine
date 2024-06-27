/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Transformable
*/

#pragma once

#include "common.hpp"

namespace LE {
    class Transformable {
        public:
            virtual ~Transformable() = default;

            void setOrigin(LE::Vector<2, float> origin)
            {
                this->_origin = origin;
            }

            LE::Vector<2, float> getOrigin() const
            {
                return this->_origin;
            }

            void setPosition(LE::Vector<2, float> position)
            {
                this->_position = position;
            }

            LE::Vector<2, float> getPosition() const
            {
                return this->_position;
            }

            void setScale(LE::Vector<2, float> scale)
            {
                this->_scale = scale;
            }

            LE::Vector<2, float> getScale() const
            {
                return this->_scale;
            }

            void setRotation(float rotation)
            {
                this->_rotation = rotation;
            }

            float getRotation() const
            {
                return this->_rotation;
            }

            void move(LE::Vector<2, float> offset)
            {
                this->_position += offset;
            }

            void move(float offsetX, float offsetY)
            {
                this->_position += LE::Vector<2, float>(offsetX, offsetY);
            }

            void rotate(float angle)
            {
                this->_rotation += angle;
            }

            void scale(LE::Vector<2, float> factors)
            {
                this->_scale *= factors;
            }

            void scale(float factorX, float factorY)
            {
                this->_scale *= LE::Vector<2, float>(factorX, factorY);
            }

        private:
            LE::Vector<2, float> _origin;
            LE::Vector<2, float> _position;
            LE::Vector<2, float> _scale;
            float _rotation;
    };
}