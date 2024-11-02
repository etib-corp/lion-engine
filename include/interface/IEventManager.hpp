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
     * @enum Event
     * @brief Represents the type of an event.
     *
     * The Event enum represents the type of an event, such as a key press or release.
     * It includes the following values:
     * - LE_EVENT_NONE: No event.
     * - LE_KEY_A: The 'A' key.
     * - LE_KEY_B: The 'B' key.
     * - LE_KEY_C: The 'C' key.
     * - LE_KEY_D: The 'D' key.
     * - LE_KEY_E: The 'E' key.
     * - LE_KEY_F: The 'F' key.
     * - LE_KEY_G: The 'G' key.
     * - LE_KEY_H: The 'H' key.
     * - LE_KEY_I: The 'I' key.
     * - LE_KEY_J: The 'J' key.
     * - LE_KEY_K: The 'K' key.
     * - LE_KEY_L: The 'L' key.
     * - LE_KEY_M: The 'M' key.
     * - LE_KEY_N: The 'N' key.
     * - LE_KEY_O: The 'O' key.
     * - LE_KEY_P: The 'P' key.
     * - LE_KEY_Q: The 'Q' key.
     * - LE_KEY_R: The 'R' key.
     * - LE_KEY_S: The 'S' key.
     * - LE_KEY_T: The 'T' key.
     * - LE_KEY_U: The 'U' key.
     * - LE_KEY_V: The 'V' key.
     * - LE_KEY_W: The 'W' key.
     * - LE_KEY_X: The 'X' key.
     * - LE_KEY_Y: The 'Y' key.
     * - LE_KEY_Z: The 'Z' key.
     * - LE_KEY_0: The '0' key.
     * - LE_KEY_1: The '1' key.
     * - LE_KEY_2: The '2' key.
     * - LE_KEY_3: The '3' key.
     * - LE_KEY_4: The '4' key.
     * - LE_KEY_5: The '5' key.
     * - LE_KEY_6: The '6' key.
     * - LE_KEY_7: The '7' key.
     * - LE_KEY_8: The '8' key.
     * - LE_KEY_9: The '9' key.
     * - LE_KEY_F1: The 'F1' key.
     * - LE_KEY_F2: The 'F2' key.
     * - LE_KEY_F3: The 'F3' key.
     * - LE_KEY_F4: The 'F4' key.
     * - LE_KEY_F5: The 'F5' key.
     * - LE_KEY_F6: The 'F6' key.
     * - LE_KEY_F7: The 'F7' key.
     * - LE_KEY_F8: The 'F8' key.
     * - LE_KEY_F9: The 'F9' key.
     * - LE_KEY_F10: The 'F10' key.
     * - LE_KEY_F11: The 'F11' key.
     * - LE_KEY_F12: The 'F12' key.
     * - LE_KEY_ESCAPE: The 'Escape' key.
     * - LE_KEY_TAB: The 'Tab' key.
     * - LE_KEY_CAPSLOCK: The 'Caps Lock' key.
     * - LE_KEY_SHIFT: The 'Shift' key.
     * - LE_KEY_CTRL: The 'Ctrl' key.
     * - LE_KEY_ALT: The 'Alt' key.
     * - LE_KEY_SPACE: The 'Space' key.
     * - LE_KEY_ENTER: The 'Enter' key.
     * - LE_KEY_BACKSPACE: The 'Backspace' key.
     * - LE_KEY_UP: The 'Up' arrow key.
     * - LE_KEY_DOWN: The 'Down' arrow key.
     * - LE_KEY_LEFT: The 'Left' arrow key.
     * - LE_KEY_RIGHT: The 'Right' arrow key.
     * - LE_KEY_COMMA: The ',' key.
     * - LE_KEY_PERIOD: The '.' key.
     * - LE_KEY_SLASH: The '/' key.
     * - LE_KEY_SEMICOLON: The ';' key.
     * - LE_KEY_QUOTE: The ''' key.
     * - LE_KEY_LEFTBRACKET: The '[' key.
     * - LE_KEY_RIGHTBRACKET: The ']' key.
     * - LE_KEY_BACKSLASH: The '\' key.
     * - LE_KEY_MINUS: The '-' key.
     * - LE_KEY_EQUALS: The '=' key.
     * - LE_KEY_GRAVE: The '`' key.
     * - LE_KEY_NUMPAD_0: The '0' key on the numpad.
     * - LE_KEY_NUMPAD_1: The '1' key on the numpad.
     * - LE_KEY_NUMPAD_2: The '2' key on the numpad.
     * - LE_KEY_NUMPAD_3: The '3' key on the numpad.
     * - LE_KEY_NUMPAD_4: The '4' key on the numpad.
     * - LE_KEY_NUMPAD_5: The '5' key on the numpad.
     * - LE_KEY_NUMPAD_6: The '6' key on the numpad.
     * - LE_KEY_NUMPAD_7: The '7' key on the numpad.
     * - LE_KEY_NUMPAD_8: The '8' key on the numpad.
     * - LE_KEY_NUMPAD_9: The '9' key on the numpad.
     * - LE_KEY_NUMPAD_PLUS: The '+' key on the numpad.
     * - LE_KEY_NUMPAD_MINUS: The '-' key on the numpad.
     * - LE_KEY_NUMPAD_MULTIPLY: The '*' key on the numpad.
     * - LE_KEY_NUMPAD_DIVIDE: The '/' key on the numpad.
     * - LE_KEY_NUMPAD_ENTER: The 'Enter' key on the numpad.
     * - LE_KEY_NUMPAD_DOT: The '.' key on the numpad.
     * - LE_KEY_PRINTSCREEN: The 'Print Screen' key.
     * - LE_KEY_SCROLLLOCK: The 'Scroll Lock' key.
     * - LE_KEY_PAUSE: The 'Pause' key.
     * - LE_KEY_INSERT: The 'Insert' key.
     * - LE_KEY_DELETE: The 'Delete' key.
     * - LE_KEY_HOME: The 'Home' key.
     * - LE_KEY_END: The 'End' key.
     * - LE_KEY_PAGEUP: The 'Page Up' key.
     * - LE_KEY_PAGEDOWN: The 'Page Down' key.
     * - LE_KEY_LEFTMETA: The 'Left Meta' key.
     * - LE_KEY_RIGHTMETA: The 'Right Meta' key.
     * - LE_KEY_APPLICATION: The 'Application' key.
     * - LE_MOUSE_BUTTON_LEFT: The left mouse button.
     * - LE_MOUSE_BUTTON_RIGHT: The right mouse button.
     * - LE_MOUSE_BUTTON_MIDDLE: The middle mouse button.
     * - LE_MOUSE_BUTTON_X1: The X1 mouse button.
     * - LE_MOUSE_BUTTON_X2: The X2 mouse button.
     */
    typedef enum {
        LE_EVENT_NONE = -1,

        // Letters
        LE_KEY_A = 0,
        LE_KEY_B = 1,
        LE_KEY_C = 2,
        LE_KEY_D = 3,
        LE_KEY_E = 4,
        LE_KEY_F = 5,
        LE_KEY_G = 6,
        LE_KEY_H = 7,
        LE_KEY_I = 8,
        LE_KEY_J = 9,
        LE_KEY_K = 10,
        LE_KEY_L = 11,
        LE_KEY_M = 12,
        LE_KEY_N = 13,
        LE_KEY_O = 14,
        LE_KEY_P = 15,
        LE_KEY_Q = 16,
        LE_KEY_R = 17,
        LE_KEY_S = 18,
        LE_KEY_T = 19,
        LE_KEY_U = 20,
        LE_KEY_V = 21,
        LE_KEY_W = 22,
        LE_KEY_X = 23,
        LE_KEY_Y = 24,
        LE_KEY_Z = 25,

        // Numbers
        LE_KEY_0 = 26,
        LE_KEY_1 = 27,
        LE_KEY_2 = 28,
        LE_KEY_3 = 29,
        LE_KEY_4 = 30,
        LE_KEY_5 = 31,
        LE_KEY_6 = 32,
        LE_KEY_7 = 33,
        LE_KEY_8 = 34,
        LE_KEY_9 = 35,

        // Function Keys
        LE_KEY_F1 = 36,
        LE_KEY_F2 = 37,
        LE_KEY_F3 = 38,
        LE_KEY_F4 = 39,
        LE_KEY_F5 = 40,
        LE_KEY_F6 = 41,
        LE_KEY_F7 = 42,
        LE_KEY_F8 = 43,
        LE_KEY_F9 = 44,
        LE_KEY_F10 = 45,
        LE_KEY_F11 = 46,
        LE_KEY_F12 = 47,

        // Special Keys
        LE_KEY_ESCAPE = 48,
        LE_KEY_TAB = 49,
        LE_KEY_CAPSLOCK = 50,
        LE_KEY_LSHIFT = 51,
        LE_KEY_RSHIFT = 52,
        LE_KEY_LCTRL = 53,
        LE_KEY_RCTRL = 54,
        LE_KEY_LALT = 55,
        LE_KEY_RALT = 56,
        LE_KEY_SPACE = 57,
        LE_KEY_ENTER = 58,
        LE_KEY_BACKSPACE = 59,

        // Arrow Keys
        LE_KEY_UP = 60,
        LE_KEY_DOWN = 61,
        LE_KEY_LEFT = 62,
        LE_KEY_RIGHT = 63,

        // Punctuation and Misc
        LE_KEY_COMMA = 64,
        LE_KEY_PERIOD = 65,
        LE_KEY_SLASH = 66,
        LE_KEY_SEMICOLON = 67,
        LE_KEY_QUOTE = 68,
        LE_KEY_LEFTBRACKET = 69,
        LE_KEY_RIGHTBRACKET = 70,
        LE_KEY_BACKSLASH = 71,
        LE_KEY_MINUS = 72,
        LE_KEY_EQUALS = 73,
        LE_KEY_GRAVE = 74,

        // Numpad Keys
        LE_KEY_NUMPAD_0 = 75,
        LE_KEY_NUMPAD_1 = 76,
        LE_KEY_NUMPAD_2 = 77,
        LE_KEY_NUMPAD_3 = 78,
        LE_KEY_NUMPAD_4 = 79,
        LE_KEY_NUMPAD_5 = 80,
        LE_KEY_NUMPAD_6 = 81,
        LE_KEY_NUMPAD_7 = 82,
        LE_KEY_NUMPAD_8 = 83,
        LE_KEY_NUMPAD_9 = 84,
        LE_KEY_NUMPAD_PLUS = 85,
        LE_KEY_NUMPAD_MINUS = 86,
        LE_KEY_NUMPAD_MULTIPLY = 87,
        LE_KEY_NUMPAD_DIVIDE = 88,
        LE_KEY_NUMPAD_ENTER = 89,
        LE_KEY_NUMPAD_DOT = 90,

        // System Keys
        LE_KEY_PRINTSCREEN = 91,
        LE_KEY_SCROLLLOCK = 92,
        LE_KEY_PAUSE = 93,
        LE_KEY_INSERT = 94,
        LE_KEY_DELETE = 95,
        LE_KEY_HOME = 96,
        LE_KEY_END = 97,
        LE_KEY_PAGEUP = 98,
        LE_KEY_PAGEDOWN = 99,

        // Windows / Meta Keys
        LE_KEY_LEFTMETA = 100,
        LE_KEY_RIGHTMETA = 101,
        LE_KEY_APPLICATION = 102,

        // Mouse Buttons
        LE_MOUSE_BUTTON_LEFT = 103,
        LE_MOUSE_BUTTON_RIGHT = 104,
        LE_MOUSE_BUTTON_MIDDLE = 105,
        LE_MOUSE_BUTTON_X1 = 106,
        LE_MOUSE_BUTTON_X2 = 107,
    } Event;


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
