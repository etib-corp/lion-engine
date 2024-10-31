/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
    #define IBUTTON_HPP_

    #include <functional>

    #include "interface/GUI/IContainer.hpp"
    #include "interface/GUI/IInteractable.hpp"

namespace LE {
    namespace GUI {
        /**
         * @brief The IButton interface
         *
         * This class is an interface that is used to create a button object by inheriting from it.
         *
         * The button is represented by 3 values: onClick, onHover and onUnhover.
         * Each value is a `std::function<void()>` that contains the function to call when the button is clicked, hovered or unhovered.
         *
         *
         * @example
         * @code
         * LE::IButton button;
         * button.setOnClickCallback([]() {
         *     std::cout << "Button clicked" << std::endl;
         * });
         * button.setOnHoverCallback([]() {
         *     std::cout << "Button hovered" << std::endl;
         * });
         * button.setOnUnhoverCallback([]() {
         *     std::cout << "Button unhovered" << std::endl;
         * });
         * @endcode
         *
         */
        class IButton : public IInteractable, public IContainer {
            public:
                /**
                 * @brief Default destructor.
                 */
                virtual ~IButton() = default;

                /**
                 * @brief Initialize the button
                 *
                 * @return void
                 *
                */
                virtual void init() = 0;

                /**
                 * @brief Set the onClick callback
                 *
                 * This function is called when the button is clicked. (In the GUI Manager, so you don't have to call it yourself)
                 *
                 * @return void
                 *
                */
                void onClick() override;

                /**
                 * @brief Set the onHover callback
                 *
                 * This function is called when the button is hovered. (In the GUI Manager, so you don't have to call it yourself)
                 *
                 * @return void
                 *
                */
                void onHover() override;

                /**
                 * @brief Set the onUnhover callback
                 *
                 * This function is called when the button is unhovered. (In the GUI Manager, so you don't have to call it yourself))
                 *
                 * @return void
                 *
                */
                void onUnhover() override;

                /**
                 * @brief Set the onClick callback
                 *
                 * This function is called when the button is clicked.
                 *
                 * @param onClick The function to call when the button is clicked
                 * @return void
                 *
                */
                void setOnClickCallback(std::function<void()> onClick);

                /**
                 * @brief Set the onHover callback
                 *
                 * This function is called when the button is hovered.
                 *
                 * @param onHover The function to call when the button is hovered
                 * @return void
                 *
                */
                void setOnHoverCallback(std::function<void()> onHover);

                /**
                 * @brief Set the onUnhover callback
                 *
                 * This function is called when the button is unhovered.
                 *
                 * @param onUnhover The function to call when the button is unhovered
                 * @return void
                 *
                */
                void setOnUnhoverCallback(std::function<void()> onUnhover);

            protected:
                std::function<void()> _onClick;     /*!< The function to call when the button is clicked */
                std::function<void()> _onHover;     /*!< The function to call when the button is hovered */
                std::function<void()> _onUnhover;   /*!< The function to call when the button is unhovered */

        };
    }
}

#endif /* !IBUTTON_HPP_ */
