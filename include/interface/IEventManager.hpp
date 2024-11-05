/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** IEventManager
*/

#pragma once

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
     * - KEY_A: The 'A' key.
     * - KEY_B: The 'B' key.
     * - KEY_C: The 'C' key.
     * - KEY_D: The 'D' key.
     * - KEY_E: The 'E' key.
     * - KEY_F: The 'F' key.
     * - KEY_G: The 'G' key.
     * - KEY_H: The 'H' key.
     * - KEY_I: The 'I' key.
     * - KEY_J: The 'J' key.
     * - KEY_K: The 'K' key.
     * - KEY_L: The 'L' key.
     * - KEY_M: The 'M' key.
     * - KEY_N: The 'N' key.
     * - KEY_O: The 'O' key.
     * - KEY_P: The 'P' key.
     * - KEY_Q: The 'Q' key.
     * - KEY_R: The 'R' key.
     * - KEY_S: The 'S' key.
     * - KEY_T: The 'T' key.
     * - KEY_U: The 'U' key.
     * - KEY_V: The 'V' key.
     * - KEY_W: The 'W' key.
     * - KEY_X: The 'X' key.
     * - KEY_Y: The 'Y' key.
     * - KEY_Z: The 'Z' key.
     * - KEY_0: The '0' key.
     * - KEY_1: The '1' key.
     * - KEY_2: The '2' key.
     * - KEY_3: The '3' key.
     * - KEY_4: The '4' key.
     * - KEY_5: The '5' key.
     * - KEY_6: The '6' key.
     * - KEY_7: The '7' key.
     * - KEY_8: The '8' key.
     * - KEY_9: The '9' key.
     * - KEY_F1: The 'F1' key.
     * - KEY_F2: The 'F2' key.
     * - KEY_F3: The 'F3' key.
     * - KEY_F4: The 'F4' key.
     * - KEY_F5: The 'F5' key.
     * - KEY_F6: The 'F6' key.
     * - KEY_F7: The 'F7' key.
     * - KEY_F8: The 'F8' key.
     * - KEY_F9: The 'F9' key.
     * - KEY_F10: The 'F10' key.
     * - KEY_F11: The 'F11' key.
     * - KEY_F12: The 'F12' key.
     * - KEY_ESCAPE: The 'Escape' key.
     * - KEY_TAB: The 'Tab' key.
     * - KEY_CAPSLOCK: The 'Caps Lock' key.
     * - KEY_SHIFT: The 'Shift' key.
     * - KEY_CTRL: The 'Ctrl' key.
     * - KEY_ALT: The 'Alt' key.
     * - KEY_SPACE: The 'Space' key.
     * - KEY_ENTER: The 'Enter' key.
     * - KEY_BACKSPACE: The 'Backspace' key.
     * - KEY_UP: The 'Up' arrow key.
     * - KEY_DOWN: The 'Down' arrow key.
     * - KEY_LEFT: The 'Left' arrow key.
     * - KEY_RIGHT: The 'Right' arrow key.
     * - KEY_COMMA: The ',' key.
     * - KEY_PERIOD: The '.' key.
     * - KEY_SLASH: The '/' key.
     * - KEY_SEMICOLON: The ';' key.
     * - KEY_QUOTE: The ''' key.
     * - KEY_LEFTBRACKET: The '[' key.
     * - KEY_RIGHTBRACKET: The ']' key.
     * - KEY_BACKSLASH: The '\' key.
     * - KEY_MINUS: The '-' key.
     * - KEY_EQUALS: The '=' key.
     * - KEY_GRAVE: The '`' key.
     * - KEY_NUMPAD_0: The '0' key on the numpad.
     * - KEY_NUMPAD_1: The '1' key on the numpad.
     * - KEY_NUMPAD_2: The '2' key on the numpad.
     * - KEY_NUMPAD_3: The '3' key on the numpad.
     * - KEY_NUMPAD_4: The '4' key on the numpad.
     * - KEY_NUMPAD_5: The '5' key on the numpad.
     * - KEY_NUMPAD_6: The '6' key on the numpad.
     * - KEY_NUMPAD_7: The '7' key on the numpad.
     * - KEY_NUMPAD_8: The '8' key on the numpad.
     * - KEY_NUMPAD_9: The '9' key on the numpad.
     * - KEY_NUMPAD_PLUS: The '+' key on the numpad.
     * - KEY_NUMPAD_MINUS: The '-' key on the numpad.
     * - KEY_NUMPAD_MULTIPLY: The '*' key on the numpad.
     * - KEY_NUMPAD_DIVIDE: The '/' key on the numpad.
     * - KEY_NUMPAD_ENTER: The 'Enter' key on the numpad.
     * - KEY_NUMPAD_DOT: The '.' key on the numpad.
     * - KEY_PRINTSCREEN: The 'Print Screen' key.
     * - KEY_SCROLLLOCK: The 'Scroll Lock' key.
     * - KEY_PAUSE: The 'Pause' key.
     * - KEY_INSERT: The 'Insert' key.
     * - KEY_DELETE: The 'Delete' key.
     * - KEY_HOME: The 'Home' key.
     * - KEY_END: The 'End' key.
     * - KEY_PAGEUP: The 'Page Up' key.
     * - KEY_PAGEDOWN: The 'Page Down' key.
     * - KEY_LEFTMETA: The 'Left Meta' key.
     * - KEY_RIGHTMETA: The 'Right Meta' key.
     * - KEY_APPLICATION: The 'Application' key.
     * - MOUSE_BUTTON_LEFT: The left mouse button.
     * - MOUSE_BUTTON_RIGHT: The right mouse button.
     * - MOUSE_BUTTON_MIDDLE: The middle mouse button.
     * - MOUSE_BUTTON_X1: The X1 mouse button.
     * - MOUSE_BUTTON_X2: The X2 mouse button.
     * - JOYSTICK_BUTTON_A: The 'A' button on the joystick.
     * - JOYSTICK_BUTTON_B: The 'B' button on the joystick.
     * - JOYSTICK_BUTTON_X: The 'X' button on the joystick.
     * - JOYSTICK_BUTTON_Y: The 'Y' button on the joystick.
     * - JOYSTICK_BUTTON_UP: The 'Up' button on the joystick.
     * - JOYSTICK_BUTTON_DOWN: The 'Down' button on the joystick.
     * - JOYSTICK_BUTTON_LEFT: The 'Left' button on the joystick.
     * - JOYSTICK_BUTTON_RIGHT: The 'Right' button on the joystick.
     * - JOYSTICK_BUTTON_START: The 'Start' button on the joystick.
     * - JOYSTICK_BUTTON_SELECT: The 'Select' button on the joystick.
     * - JOYSTICK_BUTTON_LB: The 'Left Bumper' button on the joystick.
     * - JOYSTICK_BUTTON_RB: The 'Right Bumper' button on the joystick.
     * - JOYSTICK_BUTTON_LSB: The 'Left Stick Button' on the joystick.
     * - JOYSTICK_BUTTON_RSB: The 'Right Stick Button' on the joystick.
     * - JOYSTICK_AXIS_LEFT_X: The 'Left X Axis' on the joystick.
     * - JOYSTICK_AXIS_LEFT_Y: The 'Left Y Axis' on the joystick.
     * - JOYSTICK_AXIS_RIGHT_X: The 'Right X Axis' on the joystick.
     * - JOYSTICK_AXIS_RIGHT_Y: The 'Right Y Axis' on the joystick.
     * - JOYSTICK_AXIS_LT: The 'Left Trigger' on the joystick.
     * - JOYSTICK_AXIS_RT: The 'Right Trigger' on the joystick.
     */
    typedef enum {
        LE_EVENT_NONE = -1,

        // Letters
        KEY_A = 0,
        KEY_B = 1,
        KEY_C = 2,
        KEY_D = 3,
        KEY_E = 4,
        KEY_F = 5,
        KEY_G = 6,
        KEY_H = 7,
        KEY_I = 8,
        KEY_J = 9,
        KEY_K = 10,
        KEY_L = 11,
        KEY_M = 12,
        KEY_N = 13,
        KEY_O = 14,
        KEY_P = 15,
        KEY_Q = 16,
        KEY_R = 17,
        KEY_S = 18,
        KEY_T = 19,
        KEY_U = 20,
        KEY_V = 21,
        KEY_W = 22,
        KEY_X = 23,
        KEY_Y = 24,
        KEY_Z = 25,

        // Numbers
        KEY_0 = 26,
        KEY_1 = 27,
        KEY_2 = 28,
        KEY_3 = 29,
        KEY_4 = 30,
        KEY_5 = 31,
        KEY_6 = 32,
        KEY_7 = 33,
        KEY_8 = 34,
        KEY_9 = 35,

        // Function Keys
        KEY_F1 = 36,
        KEY_F2 = 37,
        KEY_F3 = 38,
        KEY_F4 = 39,
        KEY_F5 = 40,
        KEY_F6 = 41,
        KEY_F7 = 42,
        KEY_F8 = 43,
        KEY_F9 = 44,
        KEY_F10 = 45,
        KEY_F11 = 46,
        KEY_F12 = 47,

        // Special Keys
        KEY_ESCAPE = 48,
        KEY_TAB = 49,
        KEY_CAPSLOCK = 50,
        KEY_LSHIFT = 51,
        KEY_RSHIFT = 52,
        KEY_LCTRL = 53,
        KEY_RCTRL = 54,
        KEY_LALT = 55,
        KEY_RALT = 56,
        KEY_SPACE = 57,
        KEY_ENTER = 58,
        KEY_BACKSPACE = 59,

        // Arrow Keys
        KEY_UP = 60,
        KEY_DOWN = 61,
        KEY_LEFT = 62,
        KEY_RIGHT = 63,

        // Punctuation and Misc
        KEY_COMMA = 64,
        KEY_PERIOD = 65,
        KEY_SLASH = 66,
        KEY_SEMICOLON = 67,
        KEY_QUOTE = 68,
        KEY_LEFTBRACKET = 69,
        KEY_RIGHTBRACKET = 70,
        KEY_BACKSLASH = 71,
        KEY_MINUS = 72,
        KEY_EQUALS = 73,
        KEY_GRAVE = 74,

        // Numpad Keys
        KEY_NUMPAD_0 = 75,
        KEY_NUMPAD_1 = 76,
        KEY_NUMPAD_2 = 77,
        KEY_NUMPAD_3 = 78,
        KEY_NUMPAD_4 = 79,
        KEY_NUMPAD_5 = 80,
        KEY_NUMPAD_6 = 81,
        KEY_NUMPAD_7 = 82,
        KEY_NUMPAD_8 = 83,
        KEY_NUMPAD_9 = 84,
        KEY_NUMPAD_PLUS = 85,
        KEY_NUMPAD_MINUS = 86,
        KEY_NUMPAD_MULTIPLY = 87,
        KEY_NUMPAD_DIVIDE = 88,
        KEY_NUMPAD_ENTER = 89,
        KEY_NUMPAD_DOT = 90,

        // System Keys
        KEY_PRINTSCREEN = 91,
        KEY_SCROLLLOCK = 92,
        KEY_PAUSE = 93,
        KEY_INSERT = 94,
        KEY_DELETE = 95,
        KEY_HOME = 96,
        KEY_END = 97,
        KEY_PAGEUP = 98,
        KEY_PAGEDOWN = 99,

        // Windows / Meta Keys
        KEY_LEFTMETA = 100,
        KEY_RIGHTMETA = 101,
        KEY_APPLICATION = 102,

        // Mouse Buttons
        MOUSE_BUTTON_LEFT = 103,
        MOUSE_BUTTON_RIGHT = 104,
        MOUSE_BUTTON_MIDDLE = 105,
        MOUSE_BUTTON_X1 = 106,
        MOUSE_BUTTON_X2 = 107,

        JOYSTICK_BUTTON_A = 108,
        JOYSTICK_BUTTON_B = 109,
        JOYSTICK_BUTTON_X = 110,
        JOYSTICK_BUTTON_Y = 111,
        JOYSTICK_BUTTON_UP = 112,
        JOYSTICK_BUTTON_DOWN = 113,
        JOYSTICK_BUTTON_LEFT = 114,
        JOYSTICK_BUTTON_RIGHT = 115,
        JOYSTICK_BUTTON_START = 116,
        JOYSTICK_BUTTON_SELECT = 117,
        JOYSTICK_BUTTON_LB = 118,
        JOYSTICK_BUTTON_RB = 119,
        JOYSTICK_BUTTON_LSB = 120,
        JOYSTICK_BUTTON_RSB = 121,

        JOYSTICK_AXIS_LEFT_X = 122,
        JOYSTICK_AXIS_LEFT_Y = 123,
        JOYSTICK_AXIS_RIGHT_X = 124,
        JOYSTICK_AXIS_RIGHT_Y = 125,
        JOYSTICK_AXIS_LT = 126,
        JOYSTICK_AXIS_RT = 127,
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
    typedef struct Key_s
    {
        Input input;                    ///< The input source of the event.
        Event key;                      ///< The key code of the event.
        Type type = LE::PRESSED;        ///< The type of the event.
        bool _alreadyPressed = false;   ///< A boolean value indicating whether the key was already pressed.
        float axisDeadzone = 10.0f;     ///< The deadzone for joystick axis events.

        void setAlreadyPressed(bool value) const
        {
            const_cast<Key_s *>(this)->_alreadyPressed = value;
        }

        bool operator<(const Key_s &other) const
        {
            return std::tie(input, key, type) < std::tie(other.input, other.key, other.type);
        }

        bool operator==(const Key_s &other) const
        {
            return input == other.input && key == other.key && type == other.type;
        }
    } Key;


    /**
     * @union EventCallback
     * @brief Represents a callback function for an event.
     *
     * callback: A callback function that takes an Engine object and a float parameter for the delta time.
     * callbackAxis: A callback function that takes an Engine object, a first float parameter for the delta time and another float parameter for the axis value.
     */
    typedef struct EventCallback_s {
        EventCallback_s() = default;
        EventCallback_s(std::function<void(LE::IEngine &, float)> callback) : callback(callback) {}
        EventCallback_s(std::function<void(LE::IEngine &, float, float)> callbackAxis) : callbackAxis(callbackAxis) {}

        std::function<void(LE::IEngine &, float)> callback;
        std::function<void(LE::IEngine &, float, float)> callbackAxis;
        enum Type { UNKNOWN = -1, CALLBACK, CALLBACK_AXIS } type = UNKNOWN;

        bool operator==(const EventCallback_s &other) const
        {
            return callback.target<void(LE::IEngine &, float)>() == other.callback.target<void(LE::IEngine &, float)>();
        }
    } EventCallback;

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
            auto it = _eventCallbacks.find(key);
            if (it != _eventCallbacks.end())
            {
                return {false, "Event listener already exists for this event type."};
            }
            _eventCallbacks[key] = LE::EventCallback(callback);
            return {true, "Event listener added successfully."};
        }

        virtual Status addEventListener(const LE::Event& event, float deadZone, std::function<void(LE::IEngine &, float, float)> callback)
        {
            LE::Key key;
            key.input = LE::JOYSTICK_AXIS;
            key.key = event;
            key.axisDeadzone = deadZone;
            auto it = _eventCallbacks.find(key);
            if (it != _eventCallbacks.end())
            {
                return {false, "Event listener already exists for this event type."};
            }
            _eventCallbacks[key] = LE::EventCallback(callback);
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
            auto it = _eventCallbacks.find(key);
            if (it != _eventCallbacks.end())
            {
                _eventCallbacks.erase(key);
            }
        }

        /**
         * @brief Polls for events and dispatches them to the appropriate listeners.
         */
        virtual void pollEvents() = 0;

    protected:
        std::map<LE::Key, EventCallback> _eventCallbacks; ///< List of event callbacks.
    };
}

std::ostream &operator<<(std::ostream &os, const LE::Status &status);
std::ostream &operator<<(std::ostream &os, const LE::Key &key);

