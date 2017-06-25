#include "Imp.h"

int Imp::getX() {
	return _x;
}

int Imp::getY() {
	return _y;
}


void Imp::moveUp() {
	if (_y > 0)
		_y--;

	_direction = NORTH;
}

void Imp::moveDown() {
	if (_y < GRID_HEIGHT-1)
		_y++;

	_direction = SOUTH;
}

void Imp::moveLeft() {
	if (_x > 0)
		_x--;

	_direction = WEST;
}

void Imp::moveRight() {
	if (_x < GRID_WIDTH-1)
		_x++;

	_direction = EAST;
}

DIRECTION Imp::get_direction() {
	return _direction;
}