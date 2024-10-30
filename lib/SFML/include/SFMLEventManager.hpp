/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLEventManager
*/

#ifndef SFMLEVENTMANAGER_HPP_
    #define SFMLEVENTMANAGER_HPP_

    #include "interface/IEventManager.hpp"
    #include "SFMLCommon.hpp"

namespace LE {

    class IEngine;

    class SFMLEventManager : public LE::IEventManager {
        public:
            SFMLEventManager(LE::IEngine &engine);
            ~SFMLEventManager();

            void pollEvents() override;

        protected:
        private:
            LE::IEngine &_engine;
            sf::Event _event;
    };
}

#endif /* !SFMLEVENTMANAGER_HPP_ */
