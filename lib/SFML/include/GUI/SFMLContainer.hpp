/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLContainer
*/

#ifndef SFMLCONTAINER_HPP_
    #define SFMLCONTAINER_HPP_

    #include "interface/GUI/IContainer.hpp"

    #include "Maths/Vector2.hpp"

    #include "SFMLWindow.hpp"

namespace LE {
    namespace GUI {
        class SFMLContainer : public IContainer {
            public:
                SFMLContainer(LE::Vector3<float> position, LE::Vector2<float> size, std::shared_ptr<LE::IWindow> window);

                ~SFMLContainer();

                std::shared_ptr<LE::SFMLWindow> _window;
        };
    }
}

#endif /* !SFMLCONTAINER_HPP_ */
