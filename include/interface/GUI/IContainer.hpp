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
        /**
         * @brief The IContainer interface
         *
         * This class is an interface that is used to create a container object by inheriting from it.
         *
         * The container is represented by 2 values: children and background.
         * The children is a `std::vector<std::shared_ptr<IComponent>>` that contains the children of the container.
         * The background is a `LE::IShape` that contains the background of the container.
         *
         *
         * @example
         * @code
         * LE::IContainer container;
         * container.addChildren(std::make_shared<LE::GUI::IButton>());
         * container.setBackground(new LE::Rectangle());
         * @endcode
         *
         */
        class IContainer : public IComponent {
            public:
                /**
                 * @brief Construct a new IContainer
                 *
                 * The IContainer class is an interface that is used to create a container object.
                 *
                 * @return IContainer
                 *
                */
                virtual ~IContainer() = default;

                /**
                 * @brief Add a child to the container
                 *
                 * @param child The child to add
                 * @return void
                 *
                */
                virtual void addChildren(std::shared_ptr<IComponent> child);

                /**
                 * @brief Remove a child from the container
                 *
                 * @param id The id of the child to remove
                 * @return void
                 *
                */
                virtual void removeChildren(unsigned int id);

                /**
                 * @brief Get the children of the container
                 *
                 * @return std::vector<std::shared_ptr<IComponent>>
                 *
                */
                virtual void init();

                /**
                 * @brief Get the children of the container
                 *
                 * @return std::vector<std::shared_ptr<IComponent>>
                 *
                */
                virtual void setBackground(LE::IShape *background);

                /**
                 * @brief Get the children of the container
                 *
                 * @return std::vector<std::shared_ptr<IComponent>>
                 *
                */
                virtual void setBackgroundColor(LE::Color *color);

            protected:
                std::vector<std::shared_ptr<IComponent>> _children;     /*!< The children of the container */
                LE::IShape *_background;                                /*!< The background of the container */
        };
    }
}

#endif /* !ICONTAINER_HPP_ */
