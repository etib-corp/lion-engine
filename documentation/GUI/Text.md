# GUI Abstact Text built-in

A low-level text that provides a base for all GUI texts.

## Inheritance

- IShape
- IComponent

## Description

The GUI Abstract Text is a built-in text that provides a base for all GUI texts. It is not meant to be used directly, but rather to be extended by other texts.

We based on React components to create our GUI texts. This means that the GUI Abstract Text is a React component that provides a base for all GUI texts.

So for all interactions, if you want to create a custom GUI text, you should extend the GUI Abstract Text.

## Usage

For example, if you want to create a custom text component, which inherits from the GUI Abstract Text, you should do the following:

```cpp
class CustomText : public IText {
    public:
        CustomText() {
            // ...
        }

        void init() override {
            // Initialize the text, but take care to be compatible with all Graphical libraries
        }

        void draw() override {
            // Draw the text, but take care to be compatible with all Graphical libraries (do not call directly the draw method of the graphical library)
        }

        void setFont(std::shared_ptr<IFont> font) override {
            // Set the font of the text, but take care to be compatible with all Graphical libraries
        }

        // Your customs methods ...
};
```

## Methods (already implemented)

The GUI Abstract Text provides the following public methods:
- `size_t getId() const`: Get the ID of the text.
- `void setPos(float x, float y)`: Set the position of the text.
- `void setWidth(float width)`: Set the width of the text.
- `void setHeight(float height)`: Set the height of the text.
- `void setFont(std::shared_ptr<IFont> font)`: Set the font of the text.
- `void setContent(const std::string &content)`: Set the content of the text.
- `std::string getContent() const`: Get the content of the text.
- `std::shared_ptr<LE::GUI::IFont> getFont() const`: Get the font of the text.
- `void setCharacterSize(unsigned int size)`: Set the character size of the text.

## Properties

The GUI Abstract Text provides the following properties:
- **public**
    - `size_t _id`: The ID of the text.
- **protected**
    - `std::string _content`: The content of the text.
    - `std::shared_ptr<IFont> _font`: The font of the text.
