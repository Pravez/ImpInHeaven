SET(LOGIC_SOURCE Level.cpp Level.hpp systems/MovementSystem.hpp systems/events/CollisionSystem.hpp systems/events/DebugSystem.hpp)

SET(LOGIC_LIB IIH_Logic)

ADD_LIBRARY(${LOGIC_LIB} ${LOGIC_SOURCE})