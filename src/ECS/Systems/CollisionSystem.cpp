/*
** EPITECH PROJECT, 2024
** r-type
** File description:
** CollisionSystem
*/

#include "ECS/Systems/CollisionSystem.hpp"
#include "ECS/Ecs.hpp"
#include "interface/IEngine.hpp"


CollisionSystem::CollisionSystem()
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::update(LE::Ecs *ecs, float dt)
{
    std::vector<HurtBox> hurtboxHit;

    for (auto entity : _entities) {
        auto &hitbox = ecs->getComponent<HitBox>(entity);
        auto &transform = ecs->getComponent<TransformComponent>(entity);

        if (_rectangle != nullptr) {
            _rectangle->setPosition(LE::Vector3<float>(transform.position.x, transform.position.y, 0));
            _rectangle->resize(hitbox.width, hitbox.height);
            _rectangle->setColor(std::make_shared<LE::Color>(255, 0, 0, 255));
            _rectangle->draw();
        }

        for (auto entity2 : _entities) {
            if (entity == entity2)
                continue;
            auto &hurtbox = ecs->getComponent<HurtBox>(entity2);
            auto &transform2 = ecs->getComponent<TransformComponent>(entity2);
            std::bitset<NB_LAYERS> layers = hurtbox.layers & hitbox.masks;

            if (_rectangle != nullptr) {
                _rectangle->setPosition(LE::Vector3<float>(transform2.position.x, transform2.position.y, 0));
                _rectangle->resize(hurtbox.width, hurtbox.height);
                _rectangle->setColor(std::make_shared<LE::Color>(0, 255, 0, 255));
                _rectangle->draw();
            }

            if (layers.none())
                continue;


            if (transform.position.x < transform2.position.x + hurtbox.width &&
                transform.position.x + hitbox.width > transform2.position.x &&
                transform.position.y < transform2.position.y + hurtbox.height &&
                transform.position.y + hitbox.height > transform2.position.y) {
                hurtboxHit.push_back(hurtbox);
            }
        }
    }
    for (auto& hurtbox : hurtboxHit) {
        hurtbox.onHit();
    }
}

void CollisionSystem::createRectangle(LE::IEngine *engine)
{
    _rectangle = engine->createRectangle(
        LE::Vector3<float>(0, 0, 0),
        LE::Vector2<float>(0, 0),
        std::make_shared<LE::Color>(255, 0, 0, 255),
        engine->getWindow()
    );
}
