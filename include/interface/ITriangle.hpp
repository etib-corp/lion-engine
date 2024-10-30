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
    class ITriangle : public IShape {
        public:
            virtual ~ITriangle() = default;

            virtual void setPoint1(const LE::Vector3<float>& point1);

            virtual void setPoint2(const LE::Vector3<float>& point2);

            virtual void setPoint3(const LE::Vector3<float>& point3);

            void move(const LE::Vector3<float>& moveVector) override;

            virtual void init() = 0;

            LE::Vector3<float> getPoint1() const;

            LE::Vector3<float> getPoint2() const;

            LE::Vector3<float> getPoint3() const;


        protected:
            LE::Vector3<float> _point1;
            LE::Vector3<float> _point2;
            LE::Vector3<float> _point3;
    };
}

#endif /* !ITRIANGLE_HPP_ */
