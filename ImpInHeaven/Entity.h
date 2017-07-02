#pragma once
#include "Vector.hpp"
#include <SDL.h>

#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGHT 80

class Entity
{
private:
	Vector2<int> position;
	SDL_Rect bounds;

public:
	virtual ~Entity() = default;
	Entity(Vector2<int> position);
	Vector2<int> getPosition() const;
	SDL_Rect getBounds() const;
	
	void setBounds(int x, int y, int width, int height);
	void setPosition(Vector2<int> position);
	void setPositionX(int x);
	void setPositionY(int y);

	virtual void update() = 0;
};
