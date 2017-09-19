#ifndef IMPINHEAVEN_LEVEL_HPP
#define IMPINHEAVEN_LEVEL_HPP

#include <entityx/entityx.h>
#include "systems/events/DebugSystem.hpp"
#include "systems/MovementSystem.hpp"

class Level : public entityx::EntityX {
public:
    explicit Level() {
        systems.add<DebugSystem>();
        systems.add<MovementSystem>();
        systems.add<CollisionSystem>();
        systems.configure();

        entityx::Entity entity = entities.create();
        entity.assign<FPosition>(0, 0);
        entity.assign<Direction>(1, 0);

        entityx::Entity entity2 = entities.create();
        entity2.assign<FPosition>(10, 0);
        entity2.assign<Direction>(-1, 0);
    }

    void update(entityx::TimeDelta dt) {
        systems.update<DebugSystem>(dt);
        systems.update<MovementSystem>(dt);
        systems.update<CollisionSystem>(dt);
    }
};


#endif //IMPINHEAVEN_LEVEL_HPP
