#ifndef IMPINHEAVEN_DEBUGSYSTEM_HPP
#define IMPINHEAVEN_DEBUGSYSTEM_HPP

#include <entityx/Event.h>
#include <entityx/System.h>
#include "CollisionSystem.hpp"

class DebugSystem : public entityx::System<DebugSystem>, public entityx::Receiver<DebugSystem> {
public:
    void configure(entityx::EventManager &event_manager) {
        event_manager.subscribe<Collision>(*this);
    }

    void update(entityx::EntityManager &entities, entityx::EventManager &events, entityx::TimeDelta dt) { }
    void receive(const Collision &collision) {
        std::cout << "entities collided: " << collision.left << " and " << collision.right << std::endl;
    }
};

#endif //IMPINHEAVEN_DEBUGSYSTEM_HPP
