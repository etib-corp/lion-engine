/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IButton
*/

#ifndef IBUTTON_HPP_
    #define IBUTTON_HPP_

    #include <functional>

    #include "GUI/IContainer.hpp"
    #include "GUI/IInteractable.hpp"

namespace LE {
    namespace GUI {
        class IButton : public IInteractable, public IContainer {
            public:
                virtual ~IButton() = default;

                void onClick() override;

                void onHover() override;

                void onUnhover() override;

                void setOnClickCallback(std::function<void()> onClick);

                void setOnHoverCallback(std::function<void()> onHover);

                void setOnUnhoverCallback(std::function<void()> onUnhover);

            protected:
                std::function<void()> _onClick;
                std::function<void()> _onHover;
                std::function<void()> _onUnhover;

        };
    }
}

#endif /* !IBUTTON_HPP_ */
