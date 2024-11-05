# GUI Abstract Container built-in

A low-level container that provides a base for all GUI containers.

## Inheritance

- IComponent

## Description

The GUI Abstract Container is a built-in container that provides a base for all GUI containers. It is not meant to be used directly, but rather to be extended by other containers.

We based on React components to create our GUI containers. This means that the GUI Abstract Container is a React component that provides a base for all GUI containers.

So for all interactions, if you want to create a custom GUI container, you should extend the GUI Abstract Container.

## The basic implementation

We thought that a base container should do this kind of things:
- Manage the children of the container
- Manage the position of the children of the container
- Manage the size of the children of the container

So, we implemented the facts that a container should have children, and that it should manage the position and the size of its children.

Basically, we force centering the children of the container, but you can override this behavior by defining your own `draw` method.

## Usage

For example, if you want to create a custom container component, which inherits from the GUI Abstract Container, you should do the following:

```cpp
class CustomContainer : public IContainer {
    public:
        CustomContainer() {
            // ...
        }

        // You are not forced to override this method, but you can if you want to customize the behavior of the container
        void init() override {
            // Initialize the container, but take care to be compatible with all Graphical libraries
        }

        // You are not forced to override this method, but you can if you want to customize the behavior of the container
        void draw() override {
            // Draw the container, but take care to be compatible with all Graphical libraries (do not call directly the draw method of the graphical library)
        }

        // You are not forced to override this method, but you can if you want to customize the behavior of the container
        void setFont(std::shared_ptr<IFont> font) override {
            // Set the font of the container, but take care to be compatible with all Graphical libraries
        }

        // Your customs methods ...
};
```

## Methods (already implemented)

The GUI Abstract Container provides the following public methods:
- `size_t getId() const`: Get the ID of the container.
- `void setPos(float x, float y)`: Set the position of the container.
- `void setWidth(float width)`: Set the width of the container.
- `void setHeight(float height)`: Set the height of the container.
- `float getX() const`: Get the x position of the container.
- `float getY() const`: Get the y position of the container.
- `float getWidth() const`: Get the width of the container.
- `float getHeight() const`: Get the height of the container.
- `void addChildren(std::shared_ptr<IComponent> child)`: Add a child to the container.
- `void removeChildren(size_t id)`: Remove a child from the container.
- `void setBackground(std::shared_ptr<LE::IShape> background)` : Set the background of the container.
- `void setBackgroundColor(std::shared_ptr<LE::Color> color)`: Set the background color of the container.

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
