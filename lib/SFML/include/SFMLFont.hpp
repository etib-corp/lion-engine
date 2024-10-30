/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLFont
*/

#ifndef SFMLFONT_HPP_
    #define SFMLFONT_HPP_

#include "interface/IFont.hpp"
#include "SFMLCommon.hpp"

namespace LE {
    /**
     * @brief The SFMLFont class
     *
     * The SFMLFont class is a class that inherits from the IFont interface.
     *
     * By default, we set a height and a width, which is used in the Interface, but it's useless for sf::Font.
     *
    */
    class SFMLFont : public LE::IFont {
        public:
            /**
             * @brief Construct a new SFMLFont
             *
             * The SFMLFont class is a class that inherits from the IFont interface.
             *
             * By default, we set a height and a width, which is used in the Interface, but it's useless for sf::Font.
             *
             * @param path The path to the font file
             * @param height The height of the font
             * @param width The width of the font
             * @return SFMLFont
             *
            */
            SFMLFont(const std::string &path, unsigned int height, unsigned int width);

            /**
             * @brief Destroy the SFMLFont
             *
             * @return void
             *
            */
            ~SFMLFont();

            /**
             * @brief Initialize the font
             *
             * It simply loads the font from the path.
             *
             * @return void
             *
            */
            void init() override;

            sf::Font _font;    /*!< The font object */
    };
}

#endif /* !SFMLFONT_HPP_ */
