/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLButton
*/

#ifndef SFMLBUTTON_HPP_
    #define SFMLBUTTON_HPP_

    #include "GUI/IButton.hpp"

    #include "SFMLRectangle.hpp"
    #include "SFMLText.hpp"

namespace LE {
    namespace GUI {
        /**
         * @brief The SFMLButton class
         *
         * The SFMLButton class is a class that inherits from the IButton interface.
         *
         * It's used to create a button on the screen.
         *
        */
        class SFMLButton : public IButton {
            public:
                /**
                 * @brief Construct a new SFMLButton object
                 *
                 * @param pos The position of the button
                 * @param size The size of the button
                 * @param content The content of the button
                 */
                SFMLButton(const LE::Vector3<float> &pos, const LE::Vector2<float> &size, const std::string &content);

                /**
                 * @brief Destroy the SFMLButton object
                 *
                 */
                ~SFMLButton();

                /**
                 * @brief Initialize the button.
                 *
                 * @return void
                 */
                void init() override;
        };
    }
}

#endif /* !SFMLBUTTON_HPP_ */
