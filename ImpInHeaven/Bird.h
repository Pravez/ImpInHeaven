#pragma once

#include "Monster.h"

class Bird : public Monster
{
	private:
	public:
		Bird(Vector2 position, Vector2 dimensions, SDL_Texture* texture);
		void doAction();
		void draw(const Screen* screen) const;
};

