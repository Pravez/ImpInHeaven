#include "Imp.h"

int Imp::ids = 0;

Imp::Imp(Vector2<int> position, Vector2<int> dimensions, SDL_Texture* texture): DrawableElement(position, dimensions, texture)
{
	this->identifier = "player" + ids++;
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

bool Imp::isDead() const {
	return (state == DEAD);
}

std::string Imp::getIdentifier() const
{
	return this->identifier;
}
