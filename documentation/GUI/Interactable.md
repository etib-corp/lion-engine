# GUI Abstract Interactable built-in

A low-level interactable that provides a base for all GUI interactables.

## Inheritance

None

## Description

The GUI Abstract Interactable is a built-in interactable that provides a base for all GUI interactables. It is not meant to be used directly, but rather to be extended by other interactables.

We based on React components to create our GUI interactables. This means that the GUI Abstract Interactable is a React component that provides a base for all GUI interactables.

So for all interactions, if you want to create a custom GUI interactable, you should extend the GUI Abstract Interactable.

## Usage

For example, if you want to create a custom interactable component, which inherits from the GUI Abstract Interactable, you should do the following:

```cpp
class CustomInteractable : public IInteractable {
    public:
        CustomInteractable() {
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
            // Return true if the interactable is hovered, false otherwise
            // It must be implemented by the graphical library
        }

        bool isClicked() override {
            // Return true if the interactable is clicked, false otherwise
            // It must be implemented by the graphical library
        }

        // Your customs methods ...
};
```

## Methods (already implemented)

The GUI Abstract Interactable provides the following public methods:
- `void update()`: Update the interactable by checking if it is hovered or clicked.

## Properties

None