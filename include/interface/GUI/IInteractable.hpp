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
        class IInteractable {
            public:
                virtual ~IInteractable() = default;

                virtual void onClick() = 0;

                virtual void onHover() = 0;

                virtual void onUnhover() = 0;

                [[nodiscard]] virtual bool isHover() = 0;
        };
    }
}

#endif /* !IINTERACTABLE_HPP_ */
