/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IManager
*/

#ifndef IMANAGER_HPP_
    #define IMANAGER_HPP_

    #include "interface/GUI/IContainer.hpp"

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
        class IManager : public IContainer {
            public:
                /**
                 * @brief Default destructor.
                 */
                virtual ~IManager() = default;

                /**
                 *
                 * @param child The child to add
                 * @return void
                 *
                */
                void addChildren(std::shared_ptr<IComponent> child) override;

                size_t _lastID = 0;       /**< The last ID of the children */
        };
#endif /* !IMANAGER_HPP_ */
