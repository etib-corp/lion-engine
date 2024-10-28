/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEventManager
*/

#ifndef SFMLEVENTMANAGER_HPP_
    #define SFMLEVENTMANAGER_HPP_

    #include "interface/IEventManager.hpp"
    #include "SFMLEngine.hpp"


namespace LE {
    class SFMLEventManager : public LE::IEventManager {
        public:
            SFMLEventManager(std::shared_ptr<LE::SFMLWindow> window);
            ~SFMLEventManager();

            void pollEvents() override;

        protected:
        private:
            std::shared_ptr<LE::SFMLWindow> _window;
            sf::Event event;
    };
}

#endif /* !SFMLEVENTMANAGER_HPP_ */
