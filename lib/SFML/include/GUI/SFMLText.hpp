/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLText
*/

#ifndef SFMLTEXT_HPP_
    #define SFMLTEXT_HPP_

    #include "GUI/IText.hpp"
    #include "SFMLFont.hpp"
    #include "SFMLCommon.hpp"

namespace LE {
    namespace GUI {
        /**
         * @brief The SFMLText class
         *
         * The SFMLText class is a class that inherits from the IText interface.
         *
         * @example
         * @code
         * LE::SFMLText text;
         * text.setContent("Hello, World!");
         * text.setFont(std::make_shared<MyFontClass>());
         * @endcode
         *
        */
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
                SFMLText(const LE::Vector3<float> &pos, const std::string &content = "Hello, World !", Color *color = nullptr);

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
                void setColor(Color *color) override;

                /**
                 * @brief Get the content of the text
                 *
                 * @return std::string
                 *
                */
                float getWidth() const override;

                /**
                 * @brief Get the font of the text
                 *
                 * @return std::shared_ptr<IFont>
                 *
                */
                float getHeight() const override;

            protected:
                sf::Text *_text;    /*!< The text object interpreted in SFML */
        };
    }
}

#endif /* !SFMLTEXT_HPP_ */
