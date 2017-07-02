#pragma once

#include "Monster.h"

class Bird : public Monster
{
	private:
	public:
		Bird(Vector2<int> position, Vector2<int> dimensions, SDL_Texture* texture);
		void doAction();
		void draw(const Screen* screen) const;
};

