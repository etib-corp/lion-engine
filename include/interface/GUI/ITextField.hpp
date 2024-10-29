/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ITextField
*/

#ifndef ITEXTFIELD_HPP_
    #define ITEXTFIELD_HPP_

    #include "interface/GUI/IContainer.hpp"
    #include "interface/GUI/IInteractable.hpp"

    #include "IText.hpp"

namespace LE {
    namespace GUI {
        /**
         * @brief The ITextField interface
         *
         * This class is an interface that is used to create a text field object by inheriting from it.
         *
         * The text field is represented by 3 values: placeholder, label and input.
         * The placeholder is a `std::string` that contains the placeholder of the text field.
<<<<<<< HEAD
<<<<<<< HEAD
         * The label is a `std::shared_ptr<LE::GUI::IText>` that contains the label of the text field.
         * The input is a `std::shared_ptr<LE::GUI::IText>` that contains the input of the text field.
=======
         * The label is a `std::shared_ptr<LE::IText>` that contains the label of the text field.
         * The input is a `std::shared_ptr<LE::IText>` that contains the input of the text field.
>>>>>>> 61e6fede (chore: add missing documentation on abstract engine)
=======
         * The label is a `std::shared_ptr<LE::IText>` that contains the label of the text field.
         * The input is a `std::shared_ptr<LE::IText>` that contains the input of the text field.
>>>>>>> 75bfcf46 (chore: add missing documentation on abstract engine)
         *
         *
         * @example
         * @code
<<<<<<< HEAD
<<<<<<< HEAD
         * LE::GUI::ITextField textField;
         * textField.setPlaceholder("Enter your name");
         * textField.setLabel(std::make_shared<LE::GUI::IText>());
         * textField.setInput(std::make_shared<LE::GUI::IText>());
=======
=======
>>>>>>> 75bfcf46 (chore: add missing documentation on abstract engine)
         * LE::ITextField textField;
         * textField.setPlaceholder("Enter your name");
         * textField.setLabel(std::make_shared<LE::IText>());
         * textField.setInput(std::make_shared<LE::IText>());
<<<<<<< HEAD
>>>>>>> 61e6fede (chore: add missing documentation on abstract engine)
=======
>>>>>>> 75bfcf46 (chore: add missing documentation on abstract engine)
         * @endcode
         *
         */
        class ITextField : public IContainer, public IInteractable {
            public:
                /**
                 * @brief Default destructor.
                 */
                virtual ~ITextField() = default;

                /**
                 * @brief Set the maximum number of characters the text field can contain.
                 *
                 * @param maxChar The maximum number of characters.
                 *
                 * @return void
                 */
                void setMaxChar(unsigned int maxChar);

                /**
                 * @brief Called when the text field is clicked.
                 *
                 * @return void
                */
                void onClick() override;

                /**
                 * @brief Called when the text field is hovered.
                 *
                 * @return void
                 */
                void onHover() override;

                /**
                 * @brief Called when the text field is unhovered.
                 *
                 * @return void
                 */
                void onUnhover() override;

                /**
                 * @brief Get the string of the input.
                 *
                 * @return std::string
                 */
                std::string getInputContent() const;

                /**
                 * @brief Get the input as a shared pointer of IText.
                 *
                 * @return std::shared_ptr<LE::GUI::IText>
                 */
                std::shared_ptr<LE::GUI::IText> getInput() const;

            protected:
                std::string _placeholder;           /*!< The placeholder of the text field */
                std::shared_ptr<LE::GUI::IText> _label;  /*!< The label of the text field */
                std::shared_ptr<LE::GUI::IText> _input;  /*!< The input of the text field */
                bool _isFocus;                      /*!< The state of the text field */
                unsigned int _maxChar = 18;         /*!< The maximum number of characters the text field can contain */
        };
    }
}

#endif /* !ITEXTFIELD_HPP_ */
