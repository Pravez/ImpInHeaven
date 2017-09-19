#ifndef IMPINHEAVEN_COLLISIONSYSTEM_HPP
#define IMPINHEAVEN_COLLISIONSYSTEM_HPP

#include <entityx/entityx.h>
#include "../../../components/position.hpp"

struct Collision {
    Collision(entityx::Entity left, entityx::Entity right) : left(left), right(right) {}

    entityx::Entity left, right;
};

class CollisionSystem : public entityx::System<CollisionSystem> {
public:
    void update(entityx::EntityManager &em, entityx::EventManager &events, entityx::TimeDelta dt) override {
        entityx::ComponentHandle<FPosition> left_position, right_position;
        for (entityx::Entity left_entity : em.entities_with_components(left_position)) {
            for (entityx::Entity right_entity : em.entities_with_components(right_position)) {
                if (left_entity != right_entity) {
                    if (collide(left_position.get(), right_position.get())) {
                        events.emit<Collision>(left_entity, right_entity);
                    }
                }
            }
        }
    }
};

#endif //IMPINHEAVEN_COLLISIONSYSTEM_HPP
