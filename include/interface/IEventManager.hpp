/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IEventManager
*/

#ifndef IEVENTMANAGER_HPP_
#define IEVENTMANAGER_HPP_

#include <functional>
#include <map>
#include <memory>
#include "interface/IError.hpp"

namespace LE
{
    class IEngine;
    /**
     * @struct Status
     * @brief Represents the status of an operation.
     *
     * The Status struct represents the status of an operation, such as success or failure.
     * It includes the following values:
     * - success: A boolean value indicating whether the operation was successful.
     * - message: A string message providing additional information about the operation.
     */
    typedef struct
    {
        bool success;        ///< A boolean value indicating whether the operation was successful.
        std::string message; ///< A string message providing additional information about the operation.
    } Status;

    /**
     * @enum Type
     * @brief Represents the type of an event.
     *
     * The Type enum represents the type of an event, such as a key press or release.
     * It includes the following values:
     * - PRESSED: The key is currently pressed.
     * - RELEASED: The key is currently released.
     * - JUST_PRESSED: The key was just pressed.
     * - JUST_RELEASED: The key was just released.
     */
    typedef enum
    {
        PRESSED,      ///< The key is currently pressed.
        RELEASED,     ///< The key is currently released.
        JUST_PRESSED, ///< The key was just pressed.
        JUST_RELEASED ///< The key was just released.
    } Type;

    /**
     * @enum Input
     * @brief Represents the input source of an event.
     *
     * The Input enum represents the input source of an event, such as a keyboard or mouse.
     * It includes the following values:
     * - KEYBOARD: The event is from a keyboard.
     * - MOUSE: The event is from a mouse.
     * - JOYSTICK_BUTTON: The event is from a joystick button.
     * - JOYSTICK_AXIS: The event is from a joystick axis.
     */
    typedef enum
    {
        KEYBOARD,        ///< The event is from a keyboard.
        MOUSE,           ///< The event is from a mouse.
        JOYSTICK_BUTTON, ///< The event is from a joystick button.
        JOYSTICK_AXIS    ///< The event is from a joystick axis.
    } Input;

    /**
     * @struct Key
     * @brief Represents a key event.
     *
     * The Key struct represents a key event, including the input source, key code, and event type.
     * It includes the following values:
     * - input: The input source of the event.
     * - key: The key code of the event.
     * - type: The type of the event.
     * - _alreadyPressed: A boolean value indicating whether the key was already pressed.
     */
    typedef struct
    {
        Input input;          ///< The input source of the event.
        int key;              ///< The key code of the event.
        Type type;            ///< The type of the event.
        bool _alreadyPressed; ///< A boolean value indicating whether the key was already pressed.
    } Key;

    /**
     * @class EventManager
     * @brief Manages events within the application.
     *
     * The EventManager class is responsible for managing events within the application,
     * including registering event listeners and polling for events. It maintains a
     * collection of event listeners and dispatches events to the appropriate listeners.
     *
     * @note This class uses the EventManagerError custom exception class to handle
     * errors specific to event management.
     *
     * @see EventManagerError
     */
    class IEventManager
    {
    public:
        /**
         * @class EventManagerError
         * @brief A custom exception class for handling errors specific to the EventManager.
         *
         * This class inherits from the base Error class and is used to represent
         * errors that occur within the EventManager. It provides a constructor
         * that accepts an error message.
         *
         * @see Error
         */
        class IEventManagerError : public LE::IError
        {
        public:
            /**
             * @brief Constructs a new EventManagerError object.
             *
             * @param title The error message to be associated with this exception.
             * @param details The details of the error.
             * @param help The help message for the error.
             */
            IEventManagerError(const std::string &title, const std::string &details, const std::string &help) : IError(title, details, help) {}
        };

        /**
         * @brief Destructor for the EventManager class.
         */
        virtual ~IEventManager() = default;

        /**
         * @brief Adds an event listener for the specified key.
         *
         * This method adds an event listener for the specified key, which will be called
         * whenever the key event occurs. The callback function will be passed a pointer
         * to the Engine object.
         *
         * @param key The key to listen for.
         * @param callback The callback function to be called when the key event occurs.
         * @return A Status object indicating the success or failure of the operation.
         */
        virtual Status addEventListener(const LE::Key &key, std::function<void(LE::IEngine &, float)> callback)
        {
            auto newKey = std::make_shared<Key>(key);
            auto it = _eventCallbacks.find(newKey);
            if (it != _eventCallbacks.end())
            {
                return {false, "Event listener already exists for this event type."};
            }
            _eventCallbacks[newKey] = callback;
            return {true, "Event listener added successfully."};
        }

        /**
         * @brief Removes an event listener for the specified key.
         *
         * This method removes an event listener for the specified key, which will no longer
         * be called when the key event occurs.
         *
         * @param key The key to remove the event listener for.
         * @param callback The callback function to be removed.
         */
        virtual void removeEventListener(const LE::Key &key)
        {
            auto newKey = std::make_shared<Key>(key);
            auto it = _eventCallbacks.find(newKey);
            if (it != _eventCallbacks.end())
            {
                _eventCallbacks.erase(newKey);
            }
        }

        /**
         * @brief Polls for events and dispatches them to the appropriate listeners.
         */
        virtual void pollEvents() = 0;

    protected:
        std::map<std::shared_ptr<LE::Key>, std::function<void(LE::IEngine &, float)>> _eventCallbacks; ///< List of event callbacks.
    };
}

#endif /* !IEVENTMANAGER_HPP_ */
