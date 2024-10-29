/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** ITextField
*/

#ifndef ITEXTFIELD_HPP_
    #define ITEXTFIELD_HPP_

    #include "GUI/IContainer.hpp"
    #include "GUI/IInteractable.hpp"

    #include "IText.hpp"

namespace LE {
    namespace GUI {
        class ITextField : public IContainer, public IInteractable {
            public:
                virtual ~ITextField() = default;

                void setMaxChar(unsigned int maxChar);

                void onClick() override;

                void onHover() override;

                void onUnhover() override;

                std::string getInputContent() const;

                std::shared_ptr<LE::IText> getInput() const;

            protected:
                std::string _placeholder;
                std::shared_ptr<LE::IText> _label;
                std::shared_ptr<LE::IText> _input;
                bool _isFocus;
                unsigned int _maxChar = 18;
        };
    }
}

#endif /* !ITEXTFIELD_HPP_ */
