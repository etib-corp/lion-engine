# GUI Abstract Component built-in

A low-level component that provides a base for all GUI components.

## Description

The GUI Abstract Component is a built-in component that provides a base for all GUI components. It is not meant to be used directly, but rather to be extended by other components.

We based on React components to create our GUI components. This means that the GUI Abstract Component is a React component that provides a base for all GUI components.

So for all interactions, if you want to create a custom GUI component, you should extend the GUI Abstract Component.

## Usage

For example, if you want to create a custom button component, which inherits from the GUI Abstract Component, you should do the following:

```cpp

class CustomButton : public IComponent {
    public:
        CustomButton() {
            // ...
        }

        void init() override {
            // Initialize the button, but take care to be compatible with all Graphical libraries
        }

        void draw() override {
            // Draw the button, but take care to be compatible with all Graphical libraries (do not call directly the draw method of the graphical library)
        }

        void setFont(std::shared_ptr<IFont> font) override {
            // Set the font of the button, but take care to be compatible with all Graphical libraries
        }

        // Your customs methods ...
};
```

## Methods (already implemented)

The GUI Abstract Component provides the following public methods:
- `size_t getId() const`: Get the ID of the component.
- `void setPos(float x, float y)`: Set the position of the component.
- `void setWidth(float width)`: Set the width of the component.
- `void setHeight(float height)`: Set the height of the component.
- `float getX() const`: Get the x position of the component.
- `float getY() const`: Get the y position of the component.
- `float getWidth() const`: Get the width of the component.
- `float getHeight() const`: Get the height of the component.

## Properties

The GUI Abstract Component provides the following properties:
- **public**
    - `size_t _id`: The ID of the component.
- **protected**
    - `float _x`: The x position of the component.
    - `float _y`: The y position of the component.
    - `float _width`: The width of the component.
    - `float _height`: The height of the component.
