/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IFont
*/

#ifndef IFONT_HPP_
#define IFONT_HPP_

#include <string>

namespace LE {
    /**
     * @brief The IFont class
     *
     * This class is an interface that is used to create a font object by inheriting from it.
     *
     * The font is represented by 2 values: height and width.
     * Each value is an unsigned int.
     *
     *
     * @example
     * @code
     * LE::IFont font;
     * font.setHeight(42);
     * font.setWidth(42);
     * @endcode
     *
     */
    class IFont {
        public:
            /**
             * @brief Construct a new IFont
             *
             * The IFont class is an interface that is used to create a font object.
             *
             * @return IFont
             *
            */
            virtual ~IFont() = default;

            /**
             * @brief Initialize the font
             *
             * @return void
             *
            */
            virtual void init() = 0;

            /**
             * @brief Set the height of the font
             *
             * @param height The height of the font
             * @return void
             *
            */
            virtual void setHeight(unsigned int height);


            /**
             * @brief Set the width of the font
             *
             * @param width The width of the font
             * @return void
             *
            */
            virtual void setWidth(unsigned int width);

        protected:
            unsigned int _height;   /*!< The height of the font */
            unsigned int _width;    /*!< The width of the font */
            std::string _path;      /*!< The path to the font file */
    };
}

#endif /* !IFONT_HPP_ */
