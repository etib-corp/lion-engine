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
        class Manager final : public IContainer {
            public:
                virtual ~Manager() = default;
        };
    }
}

#endif /* !IMANAGER_HPP_ */
