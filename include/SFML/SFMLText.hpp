/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLText
*/

#ifndef SFMLTEXT_HPP_
    #define SFMLTEXT_HPP_

    #include "IText.hpp"
    #include "SFMLFont.hpp"
    #include "SFMLCommon.hpp"

namespace LE {
    class SFMLText : public LE::IText {
        public:
            /**
             * @brief Construct a new SFMLText
             *
             * The SFMLText class is a class that inherits from the IText interface.
             *
             * @param content The content of the text
             * @param color The color of the text
             * @return SFMLText
             *
            */
            SFMLText(const std::string &content = "Hello, World !", std::shared_ptr<IColor> color = nullptr);

            /**
             * @brief Destroy the SFMLText
             *
             * @return void
             *
            */
            ~SFMLText();

            /**
             * @brief Initialize the text
             *
             * @return void
             *
            */
            void init() override;

            /**
             * @brief Set the content of the text
             *
             * @param content The content of the text
             * @return void
             *
            */
            void setContent(const std::string &content) override;

            /**
             * @brief Set the font of the text
             *
             * @param font The font of the text
             * @return void
             *
            */
            void setFont(std::shared_ptr<IFont> font) override;

            /**
             * @brief Set the color of the text
             *
             * @param color The color of the text
             * @return void
             *
            */
            void setColor(std::shared_ptr<IColor> color) override;

        protected:
            sf::Text *_text;    /*!< The text object */
    };
}

#endif /* !SFMLTEXT_HPP_ */
