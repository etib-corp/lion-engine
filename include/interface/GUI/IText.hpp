/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IText
*/

#ifndef ITEXT_HPP_
    #define ITEXT_HPP_

    #include <string>
    #include <memory>

    #include "interface/IFont.hpp"

    #include "interface/IShape.hpp"
    #include "interface/GUI/IComponent.hpp"

namespace LE {
    namespace GUI {
        /**
         * @brief The IText interface
         *
         * This class is an interface that is used to create a text object by inheriting from it.
         *
         * The text is represented by 2 values: content and font.
         * The content is a `std::string` that contains the content of the text.
         * The font is a `std::shared_ptr<IFont>` that contains the font of the text.
         *
         *
         * @example
         * @code
         * LE::GUI::IText text;
         * text.setContent("Hello, World!");
         * text.setFont(std::make_shared<MyFontClass>());
         * @endcode
         *
         */
        class IText : public IShape, public GUI::IComponent {
            public:
                /**
                 * @brief Default destructor.
                 */
                virtual ~IText() = default;

                /**
                 * @brief Initialize the text
                 *
                 * @return void
                 *
                */
                virtual void init() = 0;

                /**
                 * @brief Set the content of the text
                 *
                 * @param content The content of the text
                 * @return void
                 *
                */
                virtual void setContent(const std::string &content);

                /**
                 * @brief Set the font of the text
                 *
                 * @param font The font of the text
                 * @return void
                 *
                */
                virtual void setFont(std::shared_ptr<IFont> font) override;

                /**
                 * @brief Get the content of the text
                 *
                 * @return std::string
                 *
                */
                virtual std::string getContent() const;

                /**
                 * @brief Get the font of the text
                 *
                 * @return std::shared_ptr<IFont>
                 *
                */
                virtual std::shared_ptr<IFont> getFont() const;

                /**
                 * @brief Set the character size of the text
                 *
                 * @param size The size of the character
                 *
                 * @return void
                 */
                virtual void setCharacterSize(unsigned int size);

            protected:
                std::string _content;           /*!< The content of the text */
                std::shared_ptr<IFont> _font;   /*!< The font of the text */
        };
    }
}

#endif /* !ITEXT_HPP_ */
