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
        class SFMLButton : public IButton {
            public:
                SFMLButton(const LE::Vector3<float> &pos, const LE::Vector2<float> &size, const std::string &content);
                ~SFMLButton();

                void init() override;
        };
    }
}

#endif /* !SFMLBUTTON_HPP_ */
