/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IManager
*/

#ifndef IMANAGER_HPP_
    #define IMANAGER_HPP_

    #include "GUI/IContainer.hpp"

namespace LE {
    namespace GUI {
        /**
         * @brief The IManager interface
         *
         * This class is an interface that is used to create a manager object by inheriting from it.
         *
         * The manager handles the children of the container.
         *
         * The manager is represented by 1 value: children.
         * The children is a `std::vector<std::shared_ptr<IComponent>>` that contains the children of the manager.
         *
         *
         * @example
         * @code
         * LE::IManager manager;
         * manager.addChildren(std::make_shared<LE::GUI::IButton>());
         * @endcode
         *
         */
        class Manager final : public IContainer {
            public:
                /**
                 * @brief Default destructor.
                 */
                virtual ~Manager() = default;
        };
    }
}

#endif /* !IMANAGER_HPP_ */
