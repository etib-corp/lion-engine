# GUI Abstract TextField built-in

A low-level TextField that provides for all GUI Textfield.

## Inheritance

- IContainer
- IInteractable

## Description

The GUI Abstract TextField is a built-in TextField that provides a base for all GUI interactables. It is not meant to be used directly, but rather to be extended by other interactables.

We based on React components to create our GUI interactables. This means that the GUI Abstract TextField is a React component that provides a base for all GUI interactables.

So for all interactions, if you want to create a custom GUI TextField, you should extend the GUI Abstract TextField.

## Usage

For example, if you want to create a custom TextField component, which inherits from the GUI Abstract Interactable, you should do the following:

```cpp
class CustomTextField : public ITextField {
    public:
        CustomTextField() {
            // ...
        }

        void onClick() override {
            // Handle the click event
        }

        void onHover() override {
            // Handle the hover event
        }

        void onUnhover() override {
            // Handle the unhover event
        }

        bool isHover() override {
            // Return true if the TextField is hovered, false otherwise
            // It must be implemented by the graphical library
        }

        bool isClicked() override {
            // Return true if the TextField is clicked, false otherwise
            // It must be implemented by the graphical library
        }

        void init() override {
            // ...
        }

        // Your customs methods ...
};
```

## Methods (already implemented)

The GUI Abstract Interactable provides the following public methods:
- `void update()`: Update the TextField by checking if it is hovered or clicked.
- `size_t getId() const`: Get the ID of the textfield.
- `void setPos(float x, float y)`: Set the position of the textfield.
- `void setWidth(float width)`: Set the width of the textfield.
- `void setHeight(float height)`: Set the height of the textfield.
- `float getX() const`: Get the x position of the textfield.
- `float getY() const`: Get the y position of the textfield.
- `float getWidth() const`: Get the width of the textfield.
- `float getHeight() const`: Get the height of the textfield.
- `void addChildren(std::shared_ptr<IComponent> child)`: Add a child to the textfield.
- `void removeChildren(size_t id)`: Remove a child from the textfield.
- `void setBackground(std::shared_ptr<LE::IShape> background)` : Set the background of the textfield.
- `void setBackgroundColor(std::shared_ptr<LE::Color> color)`: Set the background color of the textfield.

## Properties

The GUI Abstract Container provides the following properties:
- **public**
    - `size_t _id`: The ID of the container.
    - `std::shared_ptr<LE::IShape> _background`: The background of the container.
- **protected**
    - `float _x`: The x position of the container.
    - `float _y`: The y position of the container.
    - `float _width`: The width of the container.
    - `float _height`: The height of the container.
    - `std::vector<std::shared_ptr<IComponent>> _children`: The children of the container.
    - `std::string _placeholder`: The placeholder of the textfield.
    - `std::shared_ptr<LE::GUI::IText> _label`: The label of the textfield.
    - `std::shared_ptr<LE::GUI::IText> _input`: The input of the textfield.
    - `bool _isFocus`: The state of the text field (if the user is using it or not).
    - `unsigned int _maxChar`: The maximum amount of char which can be contained in the `_input`. (default: 18)
