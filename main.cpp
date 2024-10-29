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
        SnakeScene(const std::shared_ptr<LE::IEngine> &engine) : LE::Scene(engine)
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
    // try {
        LE::GraphicalLib lib("./build/lib/SFML/liblion-engine-SFML.so");
        std::shared_ptr<LE::IEngine> engine = lib.createEngine();

        std::shared_ptr<Snake> game = std::make_shared<Snake>();
        game->init(*engine);

        std::shared_ptr<SnakeScene> scene = std::make_shared<SnakeScene>(engine);
        std::shared_ptr<IRender2DSystem> render2d = engine->createRender2DSystem(*scene->getEcs());
        scene->init();
        game->getSceneManager()->addScene(scene, "SnakeScene");
        game->getSceneManager()->play("SnakeScene");

        engine->setFramerateLimit(60);
        engine->setGame(game);

        engine->run(true);
    // } catch (const std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }
    return 0;
}
