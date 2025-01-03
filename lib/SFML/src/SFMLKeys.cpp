/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** SFMLKeys
*/

#include "SFMLKeys.hpp"

std::map<LE::Event, int> sfmlKeys = {
    {LE::Event::KEY_A, sf::Keyboard::A},
    {LE::Event::KEY_B, sf::Keyboard::B},
    {LE::Event::KEY_C, sf::Keyboard::C},
    {LE::Event::KEY_D, sf::Keyboard::D},
    {LE::Event::KEY_E, sf::Keyboard::E},
    {LE::Event::KEY_F, sf::Keyboard::F},
    {LE::Event::KEY_G, sf::Keyboard::G},
    {LE::Event::KEY_H, sf::Keyboard::H},
    {LE::Event::KEY_I, sf::Keyboard::I},
    {LE::Event::KEY_J, sf::Keyboard::J},
    {LE::Event::KEY_K, sf::Keyboard::K},
    {LE::Event::KEY_L, sf::Keyboard::L},
    {LE::Event::KEY_M, sf::Keyboard::M},
    {LE::Event::KEY_N, sf::Keyboard::N},
    {LE::Event::KEY_O, sf::Keyboard::O},
    {LE::Event::KEY_P, sf::Keyboard::P},
    {LE::Event::KEY_Q, sf::Keyboard::Q},
    {LE::Event::KEY_R, sf::Keyboard::R},
    {LE::Event::KEY_S, sf::Keyboard::S},
    {LE::Event::KEY_T, sf::Keyboard::T},
    {LE::Event::KEY_U, sf::Keyboard::U},
    {LE::Event::KEY_V, sf::Keyboard::V},
    {LE::Event::KEY_W, sf::Keyboard::W},
    {LE::Event::KEY_X, sf::Keyboard::X},
    {LE::Event::KEY_Y, sf::Keyboard::Y},
    {LE::Event::KEY_Z, sf::Keyboard::Z},
    {LE::Event::KEY_0, sf::Keyboard::Num0},
    {LE::Event::KEY_1, sf::Keyboard::Num1},
    {LE::Event::KEY_2, sf::Keyboard::Num2},
    {LE::Event::KEY_3, sf::Keyboard::Num3},
    {LE::Event::KEY_4, sf::Keyboard::Num4},
    {LE::Event::KEY_5, sf::Keyboard::Num5},
    {LE::Event::KEY_6, sf::Keyboard::Num6},
    {LE::Event::KEY_7, sf::Keyboard::Num7},
    {LE::Event::KEY_8, sf::Keyboard::Num8},
    {LE::Event::KEY_9, sf::Keyboard::Num9},
    {LE::Event::KEY_F1, sf::Keyboard::F1},
    {LE::Event::KEY_F2, sf::Keyboard::F2},
    {LE::Event::KEY_F3, sf::Keyboard::F3},
    {LE::Event::KEY_F4, sf::Keyboard::F4},
    {LE::Event::KEY_F5, sf::Keyboard::F5},
    {LE::Event::KEY_F6, sf::Keyboard::F6},
    {LE::Event::KEY_F7, sf::Keyboard::F7},
    {LE::Event::KEY_F8, sf::Keyboard::F8},
    {LE::Event::KEY_F9, sf::Keyboard::F9},
    {LE::Event::KEY_F10, sf::Keyboard::F10},
    {LE::Event::KEY_F11, sf::Keyboard::F11},
    {LE::Event::KEY_F12, sf::Keyboard::F12},
    {LE::Event::KEY_ESCAPE, sf::Keyboard::Escape},
    {LE::Event::KEY_TAB, sf::Keyboard::Tab},
    {LE::Event::KEY_CAPSLOCK, sf::Keyboard::Unknown},
    {LE::Event::KEY_LSHIFT, sf::Keyboard::LShift},
    {LE::Event::KEY_RSHIFT, sf::Keyboard::RShift},
    {LE::Event::KEY_LCTRL, sf::Keyboard::LControl},
    {LE::Event::KEY_RCTRL, sf::Keyboard::RControl},
    {LE::Event::KEY_LALT, sf::Keyboard::LAlt},
    {LE::Event::KEY_RALT, sf::Keyboard::RAlt},
    {LE::Event::KEY_SPACE, sf::Keyboard::Space},
    {LE::Event::KEY_ENTER, sf::Keyboard::Return},
    {LE::Event::KEY_BACKSPACE, sf::Keyboard::BackSpace},
    {LE::Event::KEY_UP, sf::Keyboard::Up},
    {LE::Event::KEY_DOWN, sf::Keyboard::Down},
    {LE::Event::KEY_LEFT, sf::Keyboard::Left},
    {LE::Event::KEY_RIGHT, sf::Keyboard::Right},
    {LE::Event::KEY_COMMA, sf::Keyboard::Comma},
    {LE::Event::KEY_PERIOD, sf::Keyboard::Period},
    {LE::Event::KEY_SLASH, sf::Keyboard::Slash},
    {LE::Event::KEY_SEMICOLON, sf::Keyboard::SemiColon},
    {LE::Event::KEY_QUOTE, sf::Keyboard::Quote},
    {LE::Event::KEY_LEFTBRACKET, sf::Keyboard::LBracket},
    {LE::Event::KEY_RIGHTBRACKET, sf::Keyboard::RBracket},
    {LE::Event::KEY_BACKSLASH, sf::Keyboard::BackSlash},
    {LE::Event::KEY_MINUS, sf::Keyboard::Dash},
    {LE::Event::KEY_EQUALS, sf::Keyboard::Equal},
    {LE::Event::KEY_GRAVE, sf::Keyboard::Tilde},
    {LE::Event::KEY_NUMPAD_0, sf::Keyboard::Numpad0},
    {LE::Event::KEY_NUMPAD_1, sf::Keyboard::Numpad1},
    {LE::Event::KEY_NUMPAD_2, sf::Keyboard::Numpad2},
    {LE::Event::KEY_NUMPAD_3, sf::Keyboard::Numpad3},
    {LE::Event::KEY_NUMPAD_4, sf::Keyboard::Numpad4},
    {LE::Event::KEY_NUMPAD_5, sf::Keyboard::Numpad5},
    {LE::Event::KEY_NUMPAD_6, sf::Keyboard::Numpad6},
    {LE::Event::KEY_NUMPAD_7, sf::Keyboard::Numpad7},
    {LE::Event::KEY_NUMPAD_8, sf::Keyboard::Numpad8},
    {LE::Event::KEY_NUMPAD_9, sf::Keyboard::Numpad9},
    {LE::Event::KEY_NUMPAD_PLUS, sf::Keyboard::Add},
    {LE::Event::KEY_NUMPAD_MINUS, sf::Keyboard::Subtract},
    {LE::Event::KEY_NUMPAD_MULTIPLY, sf::Keyboard::Multiply},
    {LE::Event::KEY_NUMPAD_DIVIDE, sf::Keyboard::Divide},
    {LE::Event::KEY_NUMPAD_ENTER, sf::Keyboard::Unknown},
    {LE::Event::KEY_NUMPAD_DOT, sf::Keyboard::Unknown},
    {LE::Event::KEY_PRINTSCREEN, sf::Keyboard::Unknown},
    {LE::Event::KEY_SCROLLLOCK, sf::Keyboard::Unknown},
    {LE::Event::KEY_PAUSE, sf::Keyboard::Pause},
    {LE::Event::KEY_INSERT, sf::Keyboard::Insert},
    {LE::Event::KEY_DELETE, sf::Keyboard::Delete},
    {LE::Event::KEY_HOME, sf::Keyboard::Home},
    {LE::Event::KEY_END, sf::Keyboard::End},
    {LE::Event::KEY_PAGEUP, sf::Keyboard::PageUp},
    {LE::Event::KEY_PAGEDOWN, sf::Keyboard::PageDown},
    {LE::Event::KEY_LEFTMETA, sf::Keyboard::LSystem},
    {LE::Event::KEY_RIGHTMETA, sf::Keyboard::RSystem},
    {LE::Event::KEY_APPLICATION, sf::Keyboard::Menu},
    {LE::Event::MOUSE_BUTTON_LEFT, sf::Mouse::Left},
    {LE::Event::MOUSE_BUTTON_RIGHT, sf::Mouse::Right},
    {LE::Event::MOUSE_BUTTON_MIDDLE, sf::Mouse::Middle},
    {LE::Event::MOUSE_BUTTON_X1, sf::Mouse::XButton1},
    {LE::Event::MOUSE_BUTTON_X2, sf::Mouse::XButton2},
    {LE::Event::JOYSTICK_BUTTON_A, 0},
    {LE::Event::JOYSTICK_BUTTON_B, 1},
    {LE::Event::JOYSTICK_BUTTON_X, 2},
    {LE::Event::JOYSTICK_BUTTON_Y, 3},
    {LE::Event::JOYSTICK_BUTTON_UP, 31}, // ?
    {LE::Event::JOYSTICK_BUTTON_DOWN, 31}, // ?
    {LE::Event::JOYSTICK_BUTTON_LEFT, 31}, // ?
    {LE::Event::JOYSTICK_BUTTON_RIGHT, 31}, // ?
    {LE::Event::JOYSTICK_BUTTON_START, 7},
    {LE::Event::JOYSTICK_BUTTON_SELECT, 6},
    {LE::Event::JOYSTICK_BUTTON_LB, 4},
    {LE::Event::JOYSTICK_BUTTON_RB, 5},
    {LE::Event::JOYSTICK_BUTTON_LSB, 9},
    {LE::Event::JOYSTICK_BUTTON_RSB, 10},
    {LE::Event::JOYSTICK_AXIS_LEFT_X, sf::Joystick::Axis::X},
    {LE::Event::JOYSTICK_AXIS_LEFT_Y, sf::Joystick::Axis::Y},
    {LE::Event::JOYSTICK_AXIS_RIGHT_X, sf::Joystick::Axis::U},
    {LE::Event::JOYSTICK_AXIS_RIGHT_Y, sf::Joystick::Axis::V},
    {LE::Event::JOYSTICK_AXIS_LT, sf::Joystick::Axis::Z},
    {LE::Event::JOYSTICK_AXIS_RT, sf::Joystick::Axis::R}
};



