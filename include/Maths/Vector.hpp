/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Vector
*/

#pragma once

#include <cstring>
#include <type_traits>

namespace LE {
    template <int SIZE, typename T>
    class Vector {
        public:
            Vector()
            {
                std::memset(_data, 0, SIZE * sizeof(T));
            }

            template <typename... Args>
            Vector(Args... args)
            {
                static_assert(sizeof...(Args) == SIZE, "Invalid number of arguments");
                T data[SIZE] = {args...};
                std::memcpy(_data, data, SIZE * sizeof(T));
            }

            ~Vector() = default;

            std::enable_if_t<SIZE >= 1, T&> x()
            {
                return _data[0];
            }

            std::enable_if_t<SIZE >= 2, T&> y()
            {
                return _data[1];
            }

            std::enable_if_t<SIZE >= 3, T&> z()
            {
                return _data[2];
            }

            std::enable_if_t<SIZE >= 4, T&> w()
            {
                return _data[3];
            }

            std::enable_if_t<SIZE >= 1, const T&> x() const
            {
                return _data[0];
            }

            std::enable_if_t<SIZE >= 2, const T&> y() const
            {
                return _data[1];
            }

            std::enable_if_t<SIZE >= 3, const T&> z() const
            {
                return _data[2];
            }

            std::enable_if_t<SIZE >= 4, const T&> w() const
            {
                return _data[3];
            }

            Vector<SIZE, T> operator+(const Vector<SIZE, T>& other) const
            {
                Vector<SIZE, T> result;
                for (int i = 0; i < SIZE; i++)
                    result._data[i] = _data[i] + other._data[i];
                return result;
            }

            void operator+=(const Vector<SIZE, T>& other)
            {
                for (int i = 0; i < SIZE; i++)
                    _data[i] += other._data[i];
            }

            Vector<SIZE, T> operator-(const Vector<SIZE, T>& other) const
            {
                Vector<SIZE, T> result;
                for (int i = 0; i < SIZE; i++)
                    result._data[i] = _data[i] - other._data[i];
                return result;
            }

            void operator-=(const Vector<SIZE, T>& other)
            {
                for (int i = 0; i < SIZE; i++)
                    _data[i] -= other._data[i];
            }

            Vector<SIZE, T> operator*(const Vector<SIZE, T>& other) const
            {
                Vector<SIZE, T> result;
                for (int i = 0; i < SIZE; i++)
                    result._data[i] = _data[i] * other._data[i];
                return result;
            }

            Vector<SIZE, T> operator*(const T& scalar) const
            {
                Vector<SIZE, T> result;
                for (int i = 0; i < SIZE; i++)
                    result._data[i] = _data[i] * scalar;
                return result;
            }

            void operator*=(const Vector<SIZE, T>& other)
            {
                for (int i = 0; i < SIZE; i++)
                    _data[i] *= other._data[i];
            }

            void operator*=(const T& scalar)
            {
                for (int i = 0; i < SIZE; i++)
                    _data[i] *= scalar;
            }

            Vector<SIZE, T> operator/(const Vector<SIZE, T>& other) const
            {
                Vector<SIZE, T> result;
                for (int i = 0; i < SIZE; i++)
                    result._data[i] = _data[i] / other._data[i];
                return result;
            }

            Vector<SIZE, T> operator/(const T& scalar) const
            {
                Vector<SIZE, T> result;
                for (int i = 0; i < SIZE; i++)
                    result._data[i] = _data[i] / scalar;
                return result;
            }

            void operator/=(const Vector<SIZE, T>& other)
            {
                for (int i = 0; i < SIZE; i++)
                    _data[i] /= other._data[i];
            }

            void operator/=(const T& scalar)
            {
                for (int i = 0; i < SIZE; i++)
                    _data[i] /= scalar;
            }

        private:
            T _data[SIZE];
    };
}