#include "Imp.h"

Imp::Imp(Vector2 position, Vector2 dimensions, SDL_Texture* texture): DrawableElement(position, dimensions, texture)
{
	setDirection(NORTH);
}

void Imp::moveUp() {
	if (getY() > 0)
		getPosition().minus_y(1);

	setDirection(NORTH);
}

void Imp::moveDown() {
	if (getY() < GRID_HEIGHT-1)
		getPosition().plus_y(1);

	setDirection(SOUTH);
}

void Imp::moveLeft() {
	if (getX() > 0)
		getPosition().minus_x(1);

	setDirection(WEST);
}

void Imp::moveRight() {
	if (getX() < GRID_WIDTH-1)
		getPosition().plus_x(1);

	setDirection(EAST);
}