# GUI Abstract Button built-in

A low-level button that provides a base for all GUI buttons.

## Inheritance

- IContainer
- IInteractable

## Description

The GUI Abstract Button is a built-in button that provides a base for all GUI buttons. It is not meant to be used directly, but rather to be extended by other buttons.

We based on React components to create our GUI buttons. This means that the GUI Abstract Button is a React component that provides a base for all GUI buttons.

So for all interactions, if you want to create a custom GUI button, you should extend the GUI Abstract Button.

## Usage

For example, if you want to create a custom button component, which inherits from the GUI Abstract Button, you should do the following:

```cpp
class CustomButton : public IButton {
    public:
        CustomButton() {
            // ...
        }

        void init() override {
            // Initialize the button, but take care to be compatible with all Graphical libraries
        }

        // Your customs methods ...
};
```

## Methods (already implemented)

The GUI Abstract Button provides the following public methods:

- `size_t getId() const`: Get the ID of the button.
- `void setPos(float x, float y)`: Set the position of the button.
- `void setWidth(float width)`: Set the width of the button.
- `void setHeight(float height)`: Set the height of the button.
- `void setFont(std::shared_ptr<IFont> font)`: Set the font of the button.
- `void setContent(const std::string &content)`: Set the content of the button.
- `void setContent(std::shared_ptr<LE::GUI::IText> text)` : Set the content of the button.
- `void setOnClickCallback(std::function<void()> onClick)`: Set the callback to call when the button is clicked.
- `void setOnHoverCallback(std::function<void()> onHover)`: Set the callback to call when the button is hovered.
- `void setOnUnhoverCallback(std::function<void()> onUnhover)`: Set the callback to call when the button is unhovered.
- `std::string getContentString() const`: Get the content of the button.
- `std::shared_ptr<LE::GUI::IText> getText() const`: Get the text of the button.

## Properties

The GUI Abstract Button provides the following properties:

- **public**
    - `size_t _id`: The ID of the button.
- **protected**
    - `float _x`: The x position of the button.
    - `float _y`: The y position of the button.
    - `float _width`: The width of the button.
    - `float _height`: The height of the button.
    - `std::shared_ptr<IFont> _font`: The font of the button.
    - `std::shared_ptr<IText> _text`: The text of the button.
    - `std::function<void()> _onClick`: The callback to call when the button is clicked.
    - `std::function<void()> _onHover`: The callback to call when the button is hovered.
    - `std::function<void()> _onUnhover`: The callback to call when the button is unhovered.