#pragma once

#include "DrawableElement.h"
#include "State.h"


//TODO : Remove and use map object
#define GRID_WIDTH 15
#define GRID_HEIGHT 15

class Imp : public DrawableElement
{
private:
	State state;
public:
	Imp(Vector2 position, Vector2 dimensions, SDL_Texture* texture);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void setState(State state);
	bool isDead() const;
};
