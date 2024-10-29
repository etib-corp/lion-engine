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
        /**
         * @brief The SFMLTextField class
         *
         * The SFMLTextField class is a class that inherits from the ITextField interface.
         *
         * It's used to create a text field on the screen.
         *
        */
        class SFMLTextField : public ITextField {
            public:
                /**
                 * @brief Construct a new SFMLTextField object
                 *
                 * @param pos The position of the text field
                 * @param label The label of the text field
                 * @param placeholder The placeholder of the text field
                 */
                SFMLTextField(const LE::Vector3<float> &pos, const std::string &label = "Label", const std::string &placeholder = "Enter text");

                /**
                 * @brief Destroy the SFMLTextField object
                 *
                 */
                ~SFMLTextField();

        };
    }
}

#endif /* !SFMLTEXTFIELD_HPP_ */
