#pragma once
#include "Vector.hpp"
#include <SDL.h>

#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGHT 80

class Entity
{
private:
	Vector2 position;
	SDL_Rect bounds;

public:
	virtual ~Entity() = default;
	Entity(Vector2 position);
	Vector2 getPosition() const;
	SDL_Rect getBounds() const;
	
	void setBounds(int x, int y, int width, int height);
	void setPosition(Vector2 position);
	void setPositionX(int x);
	void setPositionY(int y);

	virtual void update() = 0;
};
