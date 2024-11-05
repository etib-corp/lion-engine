// // /*
// // ** EPITECH PROJECT, 2024
// // ** lion-engine
// // ** File description:
// // ** main
// // */

// #include "GraphicalLib.hpp"
// #include "Sound/Device.hpp"

// #include <thread>

// int id = 0;

// class Snake : public LE::IGame {
//     public:
//         void init(LE::IEngine &engine) override
//         {
//             _sceneManager = engine.createSceneManager();
//             // if (id == 1)
//             //     _clientBroker = std::make_shared<LE::ClientBroker>(engine.getNetworkModule(), "127.0.0.1", 8080);
//             // else
//             //     _serverBroker = std::make_shared<LE::ServerBroker>(engine.getNetworkModule(), 0, 8080);
//         }

//         void update() override
//         {
//             // _sceneManager->play();
//         }
// };

// class SnakeScene : public LE::Scene {
//     public:
//         SnakeScene(LE::IEngine *engine) : LE::Scene(engine)
//         {
//             _guiManager = engine->createGUIManager([=](std::shared_ptr<LE::GUI::IManager> manager) {
//                 auto button = engine->createButton([=](std::shared_ptr<LE::GUI::IButton> button) {
//                     button->setBackgroundColor(std::make_shared<LE::Color>(255, 0, 0, 255));
//                     button->setWidth(100);
//                     button->setHeight(50);
//                     button->setContent("Marvin");
//                     button->setPos(100, 100);
//                     button->setFont(engine->createFont("./assets/fonts/arial.ttf", 20, 20));
//                     button->setOnClickCallback([=]() {
//                         std::cout << "Button clicked" << std::endl;
//                     });
//                 });
//                 // auto textfield = engine->createTextField([=](std::shared_ptr<LE::GUI::ITextField> textfield) {
//                 //     textfield->setBackgroundColor(std::make_shared<LE::Color>(255, 255, 255, 255));
//                 //     textfield->setWidth(100);
//                 //     textfield->setHeight(50);
//                 //     textfield->setPos(100, 200);
//                 //     textfield->setFont(engine->createFont("./assets/fonts/arial.ttf", 20, 20));
//                 //     textfield->setPlaceholder("Enter your name");
//                 // });
//                 auto container = engine->createContainer([=](std::shared_ptr<LE::GUI::IContainer> container) {
//                     container->setBackgroundColor(std::make_shared<LE::Color>(0, 0, 255, 255));
//                     container->setWidth(200);
//                     container->setHeight(200);
//                     container->setPos(200, 200);
//                 });
//                 container->addChildren(button);

//                 manager->addChildren(container);
//             });
//         }

//         void init() override
//         {
//             auto entity = _ecs->createEntity();
//             _sprite = _engine->createSpriteComponent("/home/sleo/Pictures/C_V1.png");
//             _ecs->addComponent<std::shared_ptr<LE::ISpriteComponent>>(entity, _sprite);
//             TransformComponent transform = TransformComponent{{5, 5, 0}, {0, 0, 0}, {0.2f, 0.2f, 1.0f}};
//             _ecs->addComponent<TransformComponent>(entity, transform);

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

            _eventManager->addEventListener({LE::KEYBOARD, LE::Event::KEY_ESCAPE, LE::JUST_PRESSED}, [=](LE::IEngine &engine, float deltaTime) {
                exit(0);
            });

            _eventManager->addEventListener(LE::Event::JOYSTICK_AXIS_LEFT_X, 10.0f, [=, this](LE::IEngine &engine, float deltaTime, float value) {
                _ecs->getComponent<TransformComponent>(entity2).position.x += value / 10;
            });

            _eventManager->addEventListener(LE::Event::JOYSTICK_AXIS_LEFT_Y, 10.0f, [=, this](LE::IEngine &engine, float deltaTime, float value) {
                _ecs->getComponent<TransformComponent>(entity2).position.y += value / 10;
            });
        }

//         std::shared_ptr<LE::ISpriteComponent> _sprite;
// };

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

// #include "luacpp/luacpp.h"
// #include <iostream>
// #include <string>
// #include <vector>

// class Enemy {
// public:
//     std::string texture_obj;
//     std::vector<int> start_pos;
//     std::vector<int> end_pos;
//     float speed;
//     int life;
//     int damage;
//     std::string pattern;
//     int scale;
//     std::vector<int> rotation;

//     struct Box {
//         int height;
//         int width;
//         std::vector<int> layers;
//         std::vector<int> masks;
//     };

//     Box hurtbox;
//     Box hitbox;

//     void Print() const {
//         std::cout << "Enemy:\n";
//         std::cout << "  texture_obj: " << texture_obj << "\n";
//         std::cout << "  start_pos: [" << start_pos[0] << ", " << start_pos[1] << ", " << start_pos[2] << "]\n";
//         std::cout << "  end_pos: [" << end_pos[0] << ", " << end_pos[1] << ", " << end_pos[2] << "]\n";
//         std::cout << "  speed: " << speed << "\n";
//         std::cout << "  life: " << life << "\n";
//         std::cout << "  damage: " << damage << "\n";
//         std::cout << "  pattern: " << pattern << "\n";
//         std::cout << "  scale: " << scale << "\n";
//         std::cout << "  rotation: [" << rotation[0] << ", " << rotation[1] << ", " << rotation[2] << "]\n";
//         std::cout << "  hurtbox: { height: " << hurtbox.height << ", width: " << hurtbox.width << ", layers:" << hurtbox.layers[0] << " , mask:" << hurtbox.masks[0] << " }\n";
//         std::cout << "  hitbox: { height: " << hitbox.height << ", width: " << hitbox.width << " }\n";
//     }
// };

// std::vector<int> ConvertLuaTableToVector(const LuaTable& luaTable) {
//     std::vector<int> result;

//     luaTable.ForEach([&result](const LuaObject& key, const LuaObject& value) -> bool {
//         // Assumer que chaque valeur dans la table est un entier
//         if (value.GetType() == LUA_TNUMBER) {
//             result.push_back(value.ToInteger());
//             std::cout << "ToInteger= " << value.ToInteger() << std::endl;
//         }
//         return true;  // Continuer l'itération
//     });

//     return result;
// }

// Enemy CreateEnemyFromLua(const LuaTable& enemyTable) {
//     Enemy enemy;

//     // Charger les attributs de base
//     enemy.texture_obj = enemyTable.Get("texture_obj").ToString();

//     LuaTable startPosTable = enemyTable.Get("start_pos");
//     startPosTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.start_pos.push_back(value.ToInteger());
//         return true;
//     });

//     LuaTable endPosTable = enemyTable.Get("end_pos");
//     endPosTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.end_pos.push_back(value.ToInteger());
//         return true;
//     });

//     LuaTable rotationTable = enemyTable.Get("rotation");
//     rotationTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.rotation.push_back(value.ToInteger());
//         return true;
//     });

//     enemy.speed = enemyTable.Get("speed").ToNumber();
//     enemy.life = enemyTable.Get("life").ToInteger();
//     enemy.damage = enemyTable.Get("damage").ToInteger();
//     enemy.pattern = enemyTable.Get("pattern").ToString();
//     enemy.scale = enemyTable.Get("scale").ToInteger();

//     // Charger les sous-tables (hurtbox et hitbox)
//     LuaTable hurtboxTable = enemyTable.Get("hurtbox");
//     enemy.hurtbox.height = hurtboxTable.Get("height").ToInteger();
//     enemy.hurtbox.width = hurtboxTable.Get("width").ToInteger();
//     LuaTable hurtboxLayersTables = hurtboxTable.Get("layers");
//     enemy.hurtbox.layers = ConvertLuaTableToVector(hurtboxLayersTables);
//     // enemy.hurtbox.masks =  ConvertLuaTableToVector(hurtboxTable.Get("masks").ToPointer());

//     // Convertir les objets en LuaTable avant l'itération
//     LuaTable hurtboxLayersTable = hurtboxTable.Get("layers");
//     hurtboxLayersTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.hurtbox.layers.push_back(value.ToInteger());
//         return true;
//     });

//     LuaTable hurtboxMasksTable = hurtboxTable.Get("masks");
//     hurtboxMasksTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.hurtbox.masks.push_back(value.ToInteger());
//         return true;
//     });

//     LuaTable hitboxTable = enemyTable.Get("hitbox");
//     enemy.hitbox.height = hitboxTable.Get("height").ToInteger();
//     enemy.hitbox.width = hitboxTable.Get("width").ToInteger();

//     LuaTable hitboxLayersTable = hitboxTable.Get("layers");
//     hitboxLayersTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.hitbox.layers.push_back(value.ToInteger());
//         return true;
//     });

//     LuaTable hitboxMasksTable = hitboxTable.Get("masks");
//     hitboxMasksTable.ForEach([&enemy](const LuaObject& key, const LuaObject& value) -> bool {
//         enemy.hitbox.masks.push_back(value.ToInteger());
//         return true;
//     });

//     return enemy;
// }
// #include <vector>

// int main(int ac, char **av) {
//     LuaState l(luaL_newstate(), true);

//     bool loaded = l.DoFile(1[av]);
//     if (!loaded) {
//         cerr << "Failed to load Lua script." << endl;
//         return 1;
//     }

//     // LuaTable enemiesList = l.Get("enemies");

//     std::vector<Enemy> enemiesList;
//     LuaTable enemiesTable = l.Get("enemies");

//     enemiesTable.ForEach([&enemiesList](const LuaObject& key, const LuaObject& value) -> bool {
//         if (value.GetType() == LUA_TTABLE) {
//             enemiesList.push_back(CreateEnemyFromLua(LuaTable(value)));
//         }
//         return true;
//     });

//     // Afficher tous les ennemis pour vérifier
//     for (const auto& enemy : enemiesList) {
//         enemy.Print();
//     }

//     return 0;
// }

#include "luacpp/luacpp.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Enemy {
public:
    std::string texture_obj;
    std::vector<int> start_pos;
    std::vector<int> end_pos;
    float speed;
    int life;
    int damage;
    std::string pattern;
    int scale;
    std::vector<int> rotation;

    struct Box {
        int height;
        int width;
        std::vector<int> layers;
        std::vector<int> masks;
    };

    Box hurtbox;
    Box hitbox;

    void Print() const {
        std::cout << "Enemy:\n";
        std::cout << "  texture_obj: " << texture_obj << "\n";
        std::cout << "  start_pos: [" << start_pos[0] << ", " << start_pos[1] << ", " << start_pos[2] << "]\n";
        std::cout << "  end_pos: [" << end_pos[0] << ", " << end_pos[1] << ", " << end_pos[2] << "]\n";
        std::cout << "  speed: " << speed << "\n";
        std::cout << "  life: " << life << "\n";
        std::cout << "  damage: " << damage << "\n";
        std::cout << "  pattern: " << pattern << "\n";
        std::cout << "  scale: " << scale << "\n";
        std::cout << "  rotation: [" << rotation[0] << ", " << rotation[1] << ", " << rotation[2] << "]\n";
        std::cout << "  hurtbox: { height: " << hurtbox.height << ", width: " << hurtbox.width << ", layers:" << hurtbox.layers[0] << " , mask:" << hurtbox.masks[0] << " }\n";
        std::cout << "  hitbox: { height: " << hitbox.height << ", width: " << hitbox.width << " }\n";
    }
};

std::vector<int> ConvertLuaTableToVector(const luacpp::LuaTable& luaTable) {
    std::vector<int> result;

    luaTable.ForEach([&result](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        // Assumer que chaque valeur dans la table est un entier
        if (value.GetType() == LUA_TNUMBER) {
            result.push_back(value.ToInteger());
            std::cout << "ToInteger= " << value.ToInteger() << std::endl;
        }
        return true;  // Continuer l'itération
    });

    return result;
}

Enemy CreateEnemyFromLua(const luacpp::LuaTable& enemyTable) {
    Enemy enemy;

    // Charger les attributs de base
    enemy.texture_obj = enemyTable.Get("texture_obj").ToString();

    luacpp::LuaTable startPosTable = enemyTable.Get("start_pos");
    startPosTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.start_pos.push_back(value.ToInteger());
        return true;
    });

    luacpp::LuaTable endPosTable = enemyTable.Get("end_pos");
    endPosTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.end_pos.push_back(value.ToInteger());
        return true;
    });

    luacpp::LuaTable rotationTable = enemyTable.Get("rotation");
    rotationTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.rotation.push_back(value.ToInteger());
        return true;
    });

    enemy.speed = enemyTable.Get("speed").ToNumber();
    enemy.life = enemyTable.Get("life").ToInteger();
    enemy.damage = enemyTable.Get("damage").ToInteger();
    enemy.pattern = enemyTable.Get("pattern").ToString();
    enemy.scale = enemyTable.Get("scale").ToInteger();

    // Charger les sous-tables (hurtbox et hitbox)
    luacpp::LuaTable hurtboxTable = enemyTable.Get("hurtbox");
    enemy.hurtbox.height = hurtboxTable.Get("height").ToInteger();
    enemy.hurtbox.width = hurtboxTable.Get("width").ToInteger();
    luacpp::LuaTable hurtboxLayersTables = hurtboxTable.Get("layers");
    enemy.hurtbox.layers = ConvertLuaTableToVector(hurtboxLayersTables);
    // enemy.hurtbox.masks =  ConvertLuaTableToVector(hurtboxTable.Get("masks").ToPointer());

    // Convertir les objets en LuaTable avant l'itération
    luacpp::LuaTable hurtboxLayersTable = hurtboxTable.Get("layers");
    hurtboxLayersTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.hurtbox.layers.push_back(value.ToInteger());
        return true;
    });

    luacpp::LuaTable hurtboxMasksTable = hurtboxTable.Get("masks");
    hurtboxMasksTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.hurtbox.masks.push_back(value.ToInteger());
        return true;
    });

    luacpp::LuaTable hitboxTable = enemyTable.Get("hitbox");
    enemy.hitbox.height = hitboxTable.Get("height").ToInteger();
    enemy.hitbox.width = hitboxTable.Get("width").ToInteger();

    luacpp::LuaTable hitboxLayersTable = hitboxTable.Get("layers");
    hitboxLayersTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.hitbox.layers.push_back(value.ToInteger());
        return true;
    });

    luacpp::LuaTable hitboxMasksTable = hitboxTable.Get("masks");
    hitboxMasksTable.ForEach([&enemy](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        enemy.hitbox.masks.push_back(value.ToInteger());
        return true;
    });

    return enemy;
}
#include <vector>

int main(int ac, char **av) {
    luacpp::LuaState l(luaL_newstate(), true);

    bool loaded = l.DoFile(1[av]);
    if (!loaded) {
        cerr << "Failed to load Lua script." << endl;
        return 1;
    }

    // LuaTable enemiesList = l.Get("enemies");

    std::vector<Enemy> enemiesList;
    luacpp::LuaTable enemiesTable = l.Get("enemies");

    enemiesTable.ForEach([&enemiesList](const luacpp::LuaObject& key, const luacpp::LuaObject& value) -> bool {
        if (value.GetType() == LUA_TTABLE) {
            enemiesList.push_back(CreateEnemyFromLua(luacpp::LuaTable(value)));
        }
        return true;
    });

    // Afficher tous les ennemis pour vérifier
    for (const auto& enemy : enemiesList) {
        enemy.Print();
    }

    return 0;
}
