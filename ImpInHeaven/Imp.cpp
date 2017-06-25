#include "Imp.h"

Imp::Imp(Vector2 position, Vector2 dimensions, SDL_Texture* texture): DrawableElement(position, dimensions, texture)
{
	setDirection(NORTH);
}

void Imp::moveUp() {
	getPosition().minus_y(1);
}

void Imp::moveDown() {
	getPosition().plus_y(1);
}

void Imp::moveLeft() {
	getPosition().minus_x(1);
}

void Imp::moveRight() {
	getPosition().plus_x(1);
}

void Imp::setState(State state) {
	this->state = state;
}

bool Imp::isDead() const
{
	return (state == DEAD);
}
