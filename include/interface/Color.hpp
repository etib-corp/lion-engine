/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** Color
*/

#ifndef COLOR_HPP_
    #define COLOR_HPP_

namespace LE {
    /**
     * @brief The Color class
     *
     * This class is used to represent a color.
     * 
     * The color is represented by 4 values: red, green, blue and alpha.
     * Each value is an unsigned char between `0` and `255`.
     * 
     * The default color is white.
     *
     * @example
     * @code
     * LE::Color color(255, 0, 0, 255); // red
     * @endcode
     *
     */
    class Color {
        public:
            /**
             * @brief Construct a new Color object
             *
             * @param r The red value
             * @param g The green value
             * @param b The blue value
             * @param a The alpha value
             *
            */
            Color(unsigned char r = 255, unsigned char g = 255, unsigned char b = 255, unsigned char a = 255);

            /**
             * @brief Destroy the Color object
             *
            */
            ~Color();

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

#endif /* !COLOR_HPP_ */
