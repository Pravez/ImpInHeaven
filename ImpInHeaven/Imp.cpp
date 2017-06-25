#include "Imp.h"

void Imp::moveUp() {
	if (getY() > 0)
		getPosition().minus_y(1);

	_direction = NORTH;
}

void Imp::moveDown() {
	if (getY() < GRID_HEIGHT-1)
		getPosition().plus_y(1);

	_direction = SOUTH;
}

void Imp::moveLeft() {
	if (getX() > 0)
		getPosition().minus_x(1);

	_direction = WEST;
}

void Imp::moveRight() {
	if (getX() < GRID_WIDTH-1)
		getPosition().plus_x(1);

	_direction = EAST;
}

DIRECTION Imp::getDirection() const
{
	return _direction;
}
