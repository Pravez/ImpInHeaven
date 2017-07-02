#pragma once
#include "Vector.hpp"
#include "GameEntity.h"

class Screen;

class EntityFactory
{
public:
	static GameEntity* createPlayerEntity(Screen* screen, SDL_Texture* texture, Vector2<int> position);
};
