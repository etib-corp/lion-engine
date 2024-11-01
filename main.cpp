/*
** EPITECH PROJECT, 2024
** lion-engine
** File description:
** main
*/

#include "GraphicalLib.hpp"

#include <thread>

int id = 0;

class Snake : public LE::IGame {
    public:
        void init(LE::IEngine &engine) override
        {
            _sceneManager = engine.createSceneManager();
            // if (id == 1)
            //     _clientBroker = std::make_shared<LE::ClientBroker>(engine.getNetworkModule(), "127.0.0.1", 8080);
            // else
            //     _serverBroker = std::make_shared<LE::ServerBroker>(engine.getNetworkModule(), 0, 8080);
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
            _guiManager = engine->createGUIManager([=](std::shared_ptr<LE::GUI::IManager> manager) {
                auto button = engine->createButton([=](std::shared_ptr<LE::GUI::IButton> button) {
                    button->setBackgroundColor(std::make_shared<LE::Color>(255, 0, 0, 255));
                    button->setWidth(100);
                    button->setHeight(50);
                    button->setContent("Marvin");
                    button->setPos(100, 100);
                    button->setFont(engine->createFont("./assets/fonts/arial.ttf", 20, 20));
                    button->setOnClickCallback([=]() {
                        std::cout << "Button clicked" << std::endl;
                    });
                });
                // auto textfield = engine->createTextField([=](std::shared_ptr<LE::GUI::ITextField> textfield) {
                //     textfield->setBackgroundColor(std::make_shared<LE::Color>(255, 255, 255, 255));
                //     textfield->setWidth(100);
                //     textfield->setHeight(50);
                //     textfield->setPos(100, 200);
                //     textfield->setFont(engine->createFont("./assets/fonts/arial.ttf", 20, 20));
                //     textfield->setPlaceholder("Enter your name");
                // });
                auto container = engine->createContainer([=](std::shared_ptr<LE::GUI::IContainer> container) {
                    container->setBackgroundColor(std::make_shared<LE::Color>(0, 0, 255, 255));
                    container->setWidth(200);
                    container->setHeight(200);
                    container->setPos(200, 200);
                });
                container->addChildren(button);

                manager->addChildren(container);
            });
        }

        void init() override
        {
            auto entity = _ecs->createEntity();
            _sprite = _engine->createSpriteComponent("/home/sleo/Pictures/C_V1.png");
            _ecs->addComponent<std::shared_ptr<LE::ISpriteComponent>>(entity, _sprite);
            TransformComponent transform = TransformComponent{{5, 5, 0}, {0, 0, 0}, {0.2f, 0.2f, 1.0f}};
            _ecs->addComponent<TransformComponent>(entity, transform);

            auto entity2 = _ecs->createEntity();
            std::shared_ptr<ImageAsset> image = _engine->getAssetManager()->getAsset<ImageAsset>("r-typesheet42.png");
            _sprite = _engine->createSpriteComponent(image->getImageFile());
            _ecs->addComponent<std::shared_ptr<LE::ISpriteComponent>>(entity2, _sprite);
            TransformComponent transform2 = TransformComponent{{5, 5, 0}, {0, 0, 0}, {1.0f, 1.0f, 1.0f}};
            _ecs->addComponent<TransformComponent>(entity2, transform2);
            auto animatedSprite = createAnimatedSpriteComponent(_sprite, 33, 17);
            addAnimation(*animatedSprite, "idle", {0, 1, 2, 3, 4, 5, 6}, [](AnimatedSpriteComponent &animatedSprite) {
                std::cout << "Animation ended" << std::endl;
            }, 1.0f, true);
            animatedSprite->currentAnimation = "idle";
            _ecs->addComponent<AnimatedSpriteComponent>(entity2, *animatedSprite);
        }

        std::shared_ptr<LE::ISpriteComponent> _sprite;
};

int main(int ac, char **av)
{
    LE::GraphicalLib lib("./build/lib/SFML/liblion-engine-SFML.so"); // ! in config file
    std::shared_ptr<LE::IEngine> engine = lib.createEngine();
    engine->init();
    engine->setFramerateLimit(60); // ! in config file

    engine->setGame<Snake>();

    auto sceneSnake = engine->addScene<SnakeScene>("SnakeScene");

    engine->playScene("SnakeScene");

    engine->run(true);
    return 0;
}
