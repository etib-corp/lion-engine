/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IContainer
*/

#ifndef ICONTAINER_HPP_
    #define ICONTAINER_HPP_

    #include <memory>
    #include <vector>

    #include "GUI/IComponent.hpp"
    #include "IShape.hpp"

namespace LE {
    namespace GUI {
        class IContainer : public IComponent {
            public:
                virtual ~IContainer() = default;

                virtual void addChildren(std::shared_ptr<IComponent> child);

                virtual void removeChildren(unsigned int id);

                virtual void init();

                virtual void setBackground(LE::IShape *background);

                virtual void setBackgroundColor(LE::Color *color);

            protected:
                std::vector<std::shared_ptr<IComponent>> _children;
                LE::IShape *_background;
        };
    }
}

#endif /* !ICONTAINER_HPP_ */
