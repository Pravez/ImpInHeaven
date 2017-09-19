#ifndef IMPINHEAVEN_MOVEMENTSYSTEM_HPP
#define IMPINHEAVEN_MOVEMENTSYSTEM_HPP

#include <entityx/entityx.h>
#include "../../components/position.hpp"
#include "../../components/direction.hpp"

class MovementSystem: public entityx::System<MovementSystem> {
public:
    void update(entityx::EntityManager &em, entityx::EventManager &events, entityx::TimeDelta dt) override {
        em.each<FPosition, Direction>([dt](entityx::Entity entity, FPosition &position, Direction &direction) {
            position.x += direction.x * dt;
            position.y += direction.y * dt;
        });
    }
};


#endif //IMPINHEAVEN_MOVEMENTSYSTEM_HPP
