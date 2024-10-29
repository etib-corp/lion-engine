/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
    #define ICOMPONENT_HPP_

    #include <iostream>

namespace LE {
    namespace GUI {
        /**
         * @brief The IComponent interface
         *
         * This class is an interface that is used to create a component object by inheriting from it.
         *
         * The component is represented by 4 values: id, x, y, width and height.
         * The id is a size_t that is unique to each component.
         * The x and y are the coordinates of the component.
         * The width and height are the size of the component.
         *
         *
         * @example
         * @code
         * LE::IComponent component;
         * component.setPos(42, 42);
         * @endcode
         *
         */
        class IComponent {
            public:
                /**
                 * @brief Construct a new IComponent
                 *
                 * The IComponent class is an interface that is used to create a component object.
                 *
                 * @return IComponent
                 *
                */
                virtual ~IComponent() = default;

                /**
                 * @brief Get the id of the component
                 *
                 * The id is unique to each component. It is managed by the GUI Manager.
                 *
                 * @return size_t
                 *
                */
                size_t getId() const;

                /**
                 * @brief Set the id of the component
                 *
                 * The id is unique to each component. It is managed by the GUI Manager.
                 *
                 * @param id The id of the component
                 * @return void
                 *
                */
                virtual void init() = 0;

                /**
                 * @brief Set the position of the component
                 *
                 * @param x The x coordinate of the component
                 * @param y The y coordinate of the component
                 * @return void
                 *
                */
                void setPos(float x, float y);

                /**
                 * @brief Get the width of the component.
                 *
                 * @return float
                 */
                virtual float getWidth() const;

                /**
                 * @brief Get the height of the component.
                 *
                 * @return float
                 */
                virtual float getHeight() const;

                /**
                 * @brief Get the x coordinate of the component.
                 *
                 * @return float
                 */
                float getX() const;

                /**
                 * @brief Get the y coordinate of the component.
                 *
                 * @return float
                 */
                float getY() const;

            protected:
                size_t _id;     /*!< The id of the component */
                float _x;       /*!< The x coordinate of the component */
                float _y;       /*!< The y coordinate of the component */
                float _width;   /*!< The width of the component */
                float _height;  /*!< The height of the component */
        };
    }
}

#endif /* !ICOMPONENT_HPP_ */
