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
    #include "SFMLWindow.hpp"
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
        class SFMLText : public LE::GUI::IText {
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
                SFMLText(const LE::Vector3<float> &pos, std::shared_ptr<LE::IWindow> window, const std::string &content = "Hello, World !", std::shared_ptr<Color> color = nullptr);

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
                void setColor(std::shared_ptr<Color> color) override;

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

                /**
                 * @brief Draw the text
                 */
                void draw() override;

                void resize(float width, float height) override;

                sf::Text *_text;    /*!< The text object interpreted in SFML */
                std::shared_ptr<SFMLWindow> _window;    /*!< The window where the text will be drawn */
        };
    }
}

#endif /* !SFMLTEXT_HPP_ */
