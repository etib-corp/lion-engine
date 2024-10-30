/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IInteractable
*/

#ifndef IINTERACTABLE_HPP_
    #define IINTERACTABLE_HPP_

namespace LE {
    namespace GUI {
        /**
         * @brief The IInteractable interface
         *
         * This class is an interface that is used to create an interactable object by inheriting from it.
         *
         * The interactable is represented by 3 methods: onClick, onHover and onUnhover.
         *
         * All these methods are called by the GUI Manager when the object is clicked, hovered or unhovered.
         *
         * You have to define the behavior of `isHover` method to know if the object is hovered.
         *
         */
        class IInteractable {
            public:
                /**
                 * @brief Default destructor.
                 */
                virtual ~IInteractable() = default;

                /**
                 * @brief Set the onClick callback
                 *
                 * This function is called when the object is clicked. (In the GUI Manager, so you don't have to call it yourself)
                 *
                 * @param onClick The function to call when the object is clicked
                 * @return void
                 *
                */
                virtual void onClick() = 0;

                /**
                 * @brief Set the onHover callback
                 *
                 * This function is called when the object is hovered. (In the GUI Manager, so you don't have to call it yourself)
                 *
                 * @return void
                 *
                */
                virtual void onHover() = 0;

                /**
                 * @brief Set the onUnhover callback
                 *
                 * This function is called when the object is unhovered. (In the GUI Manager, so you don't have to call it yourself)
                 *
                 * @return void
                 *
                */
                virtual void onUnhover() = 0;

                /**
                 * @brief Set the onClick callback
                 *
                 * This function is called when the object is clicked. (In the GUI Manager, so you don't have to call it yourself)
                 *
                 * @param onClick The function to call when the object is clicked
                 * @return void
                 *
                */
                [[nodiscard]] virtual bool isHover() = 0;

                /**
                 * @brief Update the object
                 *
                 * This function is called every frame by the GUI Manager.
                 *
                 * @return void
                 *
                */
                void update();

                /**
                 * @brief Return if the object is clicked
                 *
                 * You have to define it in your class for each graphical library that you are using.
                 *
                 * @return bool
                 */
                [[nodiscard]] virtual bool isClicked() = 0;
        };
    }
}

#endif /* !IINTERACTABLE_HPP_ */
