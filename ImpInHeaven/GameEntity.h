#pragma once
#include "GraphicalComponent.h"
#include "MovementComponent.h"

class GameEntity : public GameElement
{
public:
	GameEntity(const Vector2<int> position) : GameElement(position) {}
};
