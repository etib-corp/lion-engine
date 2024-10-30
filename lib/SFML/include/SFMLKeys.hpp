/*
** EPITECH PROJECT, 2024
** graphical
** File description:
** Keys
*/

#pragma once

#include "SFMLCommon.hpp"

#define LE_EVENT_NONE               sf::Keyboard::Unknown

// Letters
#define LE_KEY_A                    sf::Keyboard::A
#define LE_KEY_B                    sf::Keyboard::B
#define LE_KEY_C                    sf::Keyboard::C
#define LE_KEY_D                    sf::Keyboard::D
#define LE_KEY_E                    sf::Keyboard::E
#define LE_KEY_F                    sf::Keyboard::F
#define LE_KEY_G                    sf::Keyboard::G
#define LE_KEY_H                    sf::Keyboard::H
#define LE_KEY_I                    sf::Keyboard::I
#define LE_KEY_J                    sf::Keyboard::J
#define LE_KEY_K                    sf::Keyboard::K
#define LE_KEY_L                    sf::Keyboard::L
#define LE_KEY_M                    sf::Keyboard::M
#define LE_KEY_N                    sf::Keyboard::N
#define LE_KEY_O                    sf::Keyboard::O
#define LE_KEY_P                    sf::Keyboard::P
#define LE_KEY_Q                    sf::Keyboard::Q
#define LE_KEY_R                    sf::Keyboard::R
#define LE_KEY_S                    sf::Keyboard::S
#define LE_KEY_T                    sf::Keyboard::T
#define LE_KEY_U                    sf::Keyboard::U
#define LE_KEY_V                    sf::Keyboard::V
#define LE_KEY_W                    sf::Keyboard::W
#define LE_KEY_X                    sf::Keyboard::X
#define LE_KEY_Y                    sf::Keyboard::Y
#define LE_KEY_Z                    sf::Keyboard::Z

// Numbers
#define LE_KEY_0                    sf::Keyboard::Num0
#define LE_KEY_1                    sf::Keyboard::Num1
#define LE_KEY_2                    sf::Keyboard::Num2
#define LE_KEY_3                    sf::Keyboard::Num3
#define LE_KEY_4                    sf::Keyboard::Num4
#define LE_KEY_5                    sf::Keyboard::Num5
#define LE_KEY_6                    sf::Keyboard::Num6
#define LE_KEY_7                    sf::Keyboard::Num7
#define LE_KEY_8                    sf::Keyboard::Num8
#define LE_KEY_9                    sf::Keyboard::Num9

// Function Keys
#define LE_KEY_F1                   sf::Keyboard::F1
#define LE_KEY_F2                   sf::Keyboard::F2
#define LE_KEY_F3                   sf::Keyboard::F3
#define LE_KEY_F4                   sf::Keyboard::F4
#define LE_KEY_F5                   sf::Keyboard::F5
#define LE_KEY_F6                   sf::Keyboard::F6
#define LE_KEY_F7                   sf::Keyboard::F7
#define LE_KEY_F8                   sf::Keyboard::F8
#define LE_KEY_F9                   sf::Keyboard::F9
#define LE_KEY_F10                  sf::Keyboard::F10
#define LE_KEY_F11                  sf::Keyboard::F11
#define LE_KEY_F12                  sf::Keyboard::F12

// Special Keys
#define LE_KEY_ESCAPE               sf::Keyboard::Escape
#define LE_KEY_TAB                  sf::Keyboard::Tab
#define LE_KEY_CAPSLOCK             sf::Keyboard::Unknown  // SFML has no direct support for CapsLock
#define LE_KEY_SHIFT                sf::Keyboard::LShift
#define LE_KEY_CTRL                 sf::Keyboard::LControl
#define LE_KEY_ALT                  sf::Keyboard::LAlt
#define LE_KEY_SPACE                sf::Keyboard::Space
#define LE_KEY_ENTER                sf::Keyboard::Enter
#define LE_KEY_BACKSPACE            sf::Keyboard::Backspace

// Arrow Keys
#define LE_KEY_UP                   sf::Keyboard::Up
#define LE_KEY_DOWN                 sf::Keyboard::Down
#define LE_KEY_LEFT                 sf::Keyboard::Left
#define LE_KEY_RIGHT                sf::Keyboard::Right

// Punctuation and Misc
#define LE_KEY_COMMA                sf::Keyboard::Comma
#define LE_KEY_PERIOD               sf::Keyboard::Period
#define LE_KEY_SLASH                sf::Keyboard::Slash
#define LE_KEY_SEMICOLON            sf::Keyboard::SemiColon
#define LE_KEY_QUOTE                sf::Keyboard::Quote
#define LE_KEY_LEFTBRACKET          sf::Keyboard::LBracket
#define LE_KEY_RIGHTBRACKET         sf::Keyboard::RBracket
#define LE_KEY_BACKSLASH            sf::Keyboard::BackSlash
#define LE_KEY_MINUS                sf::Keyboard::Dash
#define LE_KEY_EQUALS               sf::Keyboard::Equal
#define LE_KEY_GRAVE                sf::Keyboard::Tilde

// Numpad Keys
#define LE_KEY_NUMPAD_0             sf::Keyboard::Numpad0
#define LE_KEY_NUMPAD_1             sf::Keyboard::Numpad1
#define LE_KEY_NUMPAD_2             sf::Keyboard::Numpad2
#define LE_KEY_NUMPAD_3             sf::Keyboard::Numpad3
#define LE_KEY_NUMPAD_4             sf::Keyboard::Numpad4
#define LE_KEY_NUMPAD_5             sf::Keyboard::Numpad5
#define LE_KEY_NUMPAD_6             sf::Keyboard::Numpad6
#define LE_KEY_NUMPAD_7             sf::Keyboard::Numpad7
#define LE_KEY_NUMPAD_8             sf::Keyboard::Numpad8
#define LE_KEY_NUMPAD_9             sf::Keyboard::Numpad9
#define LE_KEY_NUMPAD_PLUS          sf::Keyboard::Add
#define LE_KEY_NUMPAD_MINUS         sf::Keyboard::Subtract
#define LE_KEY_NUMPAD_MULTIPLY      sf::Keyboard::Multiply
#define LE_KEY_NUMPAD_DIVIDE        sf::Keyboard::Divide
#define LE_KEY_NUMPAD_ENTER         sf::Keyboard::Enter
#define LE_KEY_NUMPAD_DOT           sf::Keyboard::Period

// System Keys
#define LE_KEY_PRINTSCREEN          sf::Keyboard::Unknown  // SFML has no direct support for PrintScreen
#define LE_KEY_SCROLLLOCK           sf::Keyboard::Unknown  // SFML has no direct support for ScrollLock
#define LE_KEY_PAUSE                sf::Keyboard::Pause
#define LE_KEY_INSERT               sf::Keyboard::Insert
#define LE_KEY_DELETE               sf::Keyboard::Delete
#define LE_KEY_HOME                 sf::Keyboard::Home
#define LE_KEY_END                  sf::Keyboard::End
#define LE_KEY_PAGEUP               sf::Keyboard::PageUp
#define LE_KEY_PAGEDOWN             sf::Keyboard::PageDown

// Windows / Meta Keys
#define LE_KEY_LEFTMETA             sf::Keyboard::LSystem
#define LE_KEY_RIGHTMETA            sf::Keyboard::RSystem
#define LE_KEY_APPLICATION          sf::Keyboard::Menu

// Mouse Buttons
#define LE_MOUSE_BUTTON_LEFT        sf::Mouse::Left
#define LE_MOUSE_BUTTON_RIGHT       sf::Mouse::Right
#define LE_MOUSE_BUTTON_MIDDLE      sf::Mouse::Middle
#define LE_MOUSE_BUTTON_X1          sf::Mouse::XButton1
#define LE_MOUSE_BUTTON_X2          sf::Mouse::XButton2

// Mouse Wheel
#define LE_MOUSE_WHEEL_UP           sf::Keyboard::Unknown  // SFML doesn't handle mouse wheel as buttons directly
#define LE_MOUSE_WHEEL_DOWN         sf::Keyboard::Unknown

// Mouse Movements (optional, for advanced binding)
#define LE_MOUSE_MOVE               sf::Keyboard::Unknown
#define LE_MOUSE_MOVE_LEFT          sf::Keyboard::Unknown
#define LE_MOUSE_MOVE_RIGHT         sf::Keyboard::Unknown
#define LE_MOUSE_MOVE_UP            sf::Keyboard::Unknown
#define LE_MOUSE_MOVE_DOWN          sf::Keyboard::Unknown

// Joystick Buttons
// SFML does not support specific joystick button names directly, you might need to use sf::Joystick::isButtonPressed and handle mapping separately.
