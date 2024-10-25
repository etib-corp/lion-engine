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

    #include "IFont.hpp"
    #include "IColor.hpp"

namespace LE {
    class IText {
        public:
            /**
             * @brief Construct a new IText
             *
             * The IText class is an interface that is used to create a text object.
             *
             * @return IText
             *
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
            virtual void setFont(std::shared_ptr<IFont> font);

            /**
             * @brief Set the color of the text
             *
             * @param color The color of the text
             * @return void
             *
            */
            virtual void setColor(std::shared_ptr<IColor> color);

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
             * @brief Get the color of the text
             *
             * @return std::shared_ptr<IColor>
             *
            */
            virtual std::shared_ptr<IColor> getColor() const;

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
            std::shared_ptr<IColor> _color; /*!< The color of the text */
    };
}

#endif /* !ITEXT_HPP_ */
