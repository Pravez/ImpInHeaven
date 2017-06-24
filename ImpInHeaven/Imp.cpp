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
}

void Imp::moveDown() {
	if (_y < GRID_HEIGHT-1)
		_y++;
}

void Imp::moveLeft() {
	if (_x > 0)
		_x--;
}

void Imp::moveRight() {
	if (_x < GRID_WIDTH-1)
		_x++;
}
