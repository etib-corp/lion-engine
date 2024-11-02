/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLTextField
*/

#ifndef SFMLTEXTFIELD_HPP_
    #define SFMLTEXTFIELD_HPP_

    #include "Maths/Vector2.hpp"
    #include "GUI/ITextField.hpp"

    #include "GUI/SFMLText.hpp"
    #include "SFMLRectangle.hpp"

    #include "SFMLWindow.hpp"
    #include "SFMLKeys.hpp"

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
                SFMLTextField(const LE::Vector3<float> &pos, std::shared_ptr<LE::IWindow> window, const std::string &label = "Label", const std::string &placeholder = "Enter text");

                /**
                 * @brief Destroy the SFMLTextField object
                 *
                 */
                ~SFMLTextField();

                /**
                 * @brief Draw the text field.
                 */
                void draw() override;

                /**
                 * @brief Return if the text field is hovered.
                 */
                bool isHover() override;

                /**
                 * @brief Return if the text field is clicked.
                 */
                bool isClicked() override;

                void init() override;

                void bind(LE::IEngine *engine) override;

                std::shared_ptr<SFMLWindow> _window;            /**< The window of the text field */
        };
    }
}

#endif /* !SFMLTEXTFIELD_HPP_ */
