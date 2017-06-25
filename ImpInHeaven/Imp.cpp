#include "Imp.h"

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

DIRECTION Imp::getDirection() const
{
	return _direction;
}

void Imp::setDirection(DIRECTION direction) {
	this->_direction = direction;
}

void Imp::setState(STATE state) {
	this->state = state;
}

bool Imp::isDead() {
	return (state == DEAD);
}