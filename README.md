# Lion Engine

Lion Engine is a versatile game engine designed to support multiple graphics libraries, making it a truly multiplatform solution. Whether you're developing for Linux, Windows, Lion Engine has you covered with support for OpenGL (GLFW), SFML.

## Features

- **Multiplatform Support**: Develop games for Linux, Windows.
- **Graphics Libraries**:
    - OpenGL (GLFW) for Linux
    - SFML for Windows
- **High Performance**: Optimized for efficient rendering and resource management.
- **Extensible**: Easily add new features and customize the engine to fit your needs.

## Getting Started

### Prerequisites

- **Linux**: OpenGL, GLFW
- **Windows**: SFML

### Installationx

1. Clone the repository:
        ```sh
        git clone https://github.com/etib-corp/lion-engine.git
        ```
2. Navigate to the project directory:
        ```sh
        cd lion-engine
        ```
3. Build the engine:
        ```sh
        cmake -B build -S .
        cmake --build build
        sudo cp build/lion-engine.so mv /usr/lib
        sudo cp -r include/ /usr/include/lion-engine
        ```

## Usage

1. Create a new project using the Lion Engine template.
2. Implement your game logic.
3. Build and run your game.

## Contributing

We welcome contributions! Please read our [Contributing Guidelines](CONTRIBUTING.md) for more details.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any inquiries or support, please contact us on GitHub.

