&/*
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
            SFMLEventManager(std::shared_ptr<LE::IEngine> engine);
            ~SFMLEventManager();

            void pollEvents() override;

        protected:
        private:
            std::shared_ptr<LE::IEngine> _engine;
            sf::Event event;
    };
}

#endif /* !SFMLEVENTMANAGER_HPP_ */
