/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IColor
*/

#ifndef ICOLOR_HPP_
    #define ICOLOR_HPP_

namespace LE {
    class IColor {
        public:
            /**
             * @brief Construct a new IColor
             *
             * The IColor class is an interface that is used to create a color object.
             *
             * @return IColor
             *
            */
            virtual ~IColor() = default;

            /**
             * @brief Set the red value
             *
             * @param r The red value
             * @return void
             *
            */
            void setRed(unsigned char r);

            /**
             * @brief Set the green value
             *
             * @param g The green value
             * @return void
             *
            */
            void setGreen(unsigned char g);

            /**
             * @brief Set the blue value
             *
             * @param b The blue value
             * @return void
             *
            */
            void setBlue(unsigned char b);

            /**
             * @brief Set the alpha value
             *
             * @param a The alpha value
             * @return void
             *
            */
            void setAlpha(unsigned char a);

            /**
             * @brief Set the color
             *
             * @param r The red value
             * @param g The green value
             * @param b The blue value
             * @param a The alpha value
             * @return void
             *
            */
            void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

            /**
             * @brief Get the red value
             *
             * @return unsigned char
             *
            */
            unsigned char getRed() const;

            /**
             * @brief Get the green value
             *
             * @return unsigned char
             *
            */
            unsigned char getGreen() const;

            /**
             * @brief Get the blue value
             *
             * @return unsigned char
             *
            */
            unsigned char getBlue() const;

            /**
             * @brief Get the alpha value
             *
             * @return unsigned char
             *
            */
            unsigned char getAlpha() const;

        protected:
            unsigned char _red;   /*!< The red value */
            unsigned char _green;   /*!< The green value */
            unsigned char _blue;   /*!< The blue value */
            unsigned char _alpha;   /*!< The alpha value */
    };
}

#endif /* !ICOLOR_HPP_ */
