Here's a sample Markdown file to guide developers on creating a new game using this engine. It includes explanations for setting up the game class, scene, and engine initialization.

---

# Lion Engine Game Development Guide

Welcome to the Lion Engine! This guide will walk you through the essential steps to create a new game using the Lion Engine, from setting up the game class and scenes to initializing the engine. Follow these instructions to get started.

## Table of Contents
- [Lion Engine Game Development Guide](#lion-engine-game-development-guide)
  - [Table of Contents](#table-of-contents)
    - [Setting Up the Game Class](#setting-up-the-game-class)
      - [Explanation:](#explanation)
    - [Creating a Game Scene](#creating-a-game-scene)
      - [Explanation:](#explanation-1)
    - [Initializing the Engine and Starting the Game](#initializing-the-engine-and-starting-the-game)
      - [Explanation:](#explanation-2)

---

### Setting Up the Game Class

To start building a game, you'll need to define a main game class that inherits from `LE::IGame`. This class will manage the primary game logic and hold core components like the scene manager. Here's how to set it up:

```cpp
class Snake : public LE::IGame {
public:
    void init(LE::IEngine &engine) override {
        _sceneManager = engine.createSceneManager();
        
        // Optional: Network initialization for multiplayer
        // Uncomment for setting up a client or server
        if (id == 1) {
            _clientBroker = std::make_shared<LE::ClientBroker>(engine.getNetworkModule(), "127.0.0.1", 8080);
        } else {
            _serverBroker = std::make_shared<LE::ServerBroker>(engine.getNetworkModule(), 0, 8080);
        }
    }

    void update() override
    {
        // Place game update logic here, e.g., advancing the scene
    }

private:
    std::shared_ptr<LE::ISceneManager> _sceneManager;
    std::shared_ptr<LE::ClientBroker> _clientBroker;
    std::shared_ptr<LE::ServerBroker> _serverBroker;
};
```

#### Explanation:
- **Game Initialization (`init`)**: The `init` function is called when the game starts. Use this function to set up components like the `SceneManager`, which is crucial for managing different game scenes.
- **Networking Setup (Optional)**: If your game is multiplayer, you can initialize either a client or server broker here. Uncomment the relevant code and replace placeholder IP and port values as needed.
- **Game Update (`update`)**: This function is called each frame to update game logic. Use it to manage ongoing actions or scene transitions.

---

### Creating a Game Scene

A game scene holds the actual visual and interactive components of your game, such as entities and sprites. Define a scene by inheriting from `LE::Scene`.

```cpp
class SnakeScene : public LE::Scene {
public:
    explicit SnakeScene(LE::IEngine *engine) : LE::Scene(engine) {}

    void init() override
    {
        auto entity = _ecs->createEntity();
        
        // Load and add a sprite component to the entity
        _sprite = _engine->createSpriteComponent("/path/to/your/sprite.png");
        _ecs->addComponent<std::shared_ptr<LE::ISpriteComponent>>(entity, _sprite);
        
        // Set up a transform component
        TransformComponent transform = {{5, 5, 0}, {0, 0, 0}, {0.2f, 0.2f, 1.0f}};
        _ecs->addComponent<TransformComponent>(entity, transform);
    }

private:
    std::shared_ptr<LE::ISpriteComponent> _sprite;
};
```

#### Explanation:
- **Scene Initialization (`init`)**: This function sets up the scene's initial state. Here you can create entities, add components like sprites, and define their properties.
- **Entity Creation**: `createEntity()` is called to create a new entity in the scene.
- **Component Setup**: Components like `ISpriteComponent` and `TransformComponent` are attached to entities to define appearance and position. Adjust paths and parameters as necessary.

---

### Initializing the Engine and Starting the Game

The main function initializes the engine, configures settings, loads the game class, and starts the main game loop.

```cpp
int main(int argc, char **argv)
{
    // Load the graphical library
    LE::GraphicalLib lib("./build/lib/SFML/liblion-engine-SFML.so");
    auto engine = lib.createEngine();

    if (!engine) {
        std::cerr << "Failed to initialize engine." << std::endl;
        return -1;
    }

    engine->init();
    engine->setFramerateLimit(60); // Optionally, use a configuration file

    // Set the main game and add scenes
    engine->setGame<Snake>();
    auto sceneSnake = engine->addScene<SnakeScene>("SnakeScene");

    engine->playScene("SnakeScene");
    engine->run(true);
    return 0;
}
```

#### Explanation:
- **Loading the Library**: `GraphicalLib` loads the shared library for graphics. Update the path as needed.
- **Engine Initialization**: `createEngine()` and `init()` set up the core engine functions. If initialization fails, handle the error gracefully.
- **Game Settings**: Configure aspects like the frame rate here. Moving settings to a configuration file will make it easier to adjust without recompiling.
- **Adding Scenes**: Use `addScene<SceneName>("SceneID")` to create and store scenes.
- **Running the Game**: `engine->run(true);` starts the main game loop.
