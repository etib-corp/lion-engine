/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLTextField
*/

#ifndef SFMLTEXTFIELD_HPP_
    #define SFMLTEXTFIELD_HPP_

    #include "GUI/ITextField.hpp"
    #include "GUI/SFMLText.hpp"

namespace LE {
    namespace GUI {
        class SFMLTextField : public ITextField {
            public:
                SFMLTextField(const LE::Vector3<float> &pos, const std::string &label = "Label", const std::string &placeholder = "Enter text");
                ~SFMLTextField();

        };
    }
}

#endif /* !SFMLTEXTFIELD_HPP_ */
