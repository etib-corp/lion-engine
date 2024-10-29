/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** main
*/

#include "GraphicalLib.hpp"
#include <thread>

class Snake : public LE::IGame {
    public:
        void init(LE::IEngine &engine) override
        {
            _sceneManager = engine.createSceneManager();
        }

        void update() override
        {
            // _sceneManager->play();
        }
};

class SnakeScene : public LE::Scene {
    public:
        SnakeScene(LE::IEngine *engine) : LE::Scene(engine)
        {
        }

        void init() override
        {
            auto entity = _ecs->createEntity();
            _sprite = _engine->createSpriteComponent("/home/sleo/Pictures/C_V1.png");
            _ecs->addComponent<std::shared_ptr<LE::ISpriteComponent>>(entity, _sprite);
            TransformComponent transform = TransformComponent{{5, 5, 0}, {0, 0, 0}, {0.2f, 0.2f, 1.0f}};
            _ecs->addComponent<TransformComponent>(entity, transform);

        }

        std::shared_ptr<LE::ISpriteComponent> _sprite;

};

int main()
{
    LE::GraphicalLib lib("./build/lib/SFML/liblion-engine-SFML.so"); // ! in config file
    std::shared_ptr<LE::IEngine> engine = lib.createEngine();
    engine->setFramerateLimit(60); // ! in config file

    engine->setGame<Snake>();

    engine->addScene<SnakeScene>("SnakeScene");

    engine->playScene("SnakeScene");

    engine->run(true);
    return 0;
}
