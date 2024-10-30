/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLManager
*/

#ifndef SFMLMANAGER_HPP_
    #define SFMLMANAGER_HPP_

    #include "GUI/IManager.hpp"
    #include "SFMLWindow.hpp"

namespace LE {
    namespace GUI {
        class SFMLManager : public IManager {
            public:
                SFMLManager(std::shared_ptr<IWindow> window);

                ~SFMLManager();

                void init() override;

                std::shared_ptr<SFMLWindow> _window;

        };
    }
}

#endif /* !SFMLMANAGER_HPP_ */
