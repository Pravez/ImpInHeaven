#pragma once
#include "Vector.hpp"
#include "Direction.h"

#define DEFAULT_DIMENSIONS Vector2(50, 50)
#define DEFAULT_POSITION Vector2(0, 0)

class Element
{

protected:
	Vector2 position;
	Vector2 dimensions;

	Direction direction;

public:
	Element() : position(DEFAULT_POSITION), dimensions(DEFAULT_DIMENSIONS), direction(NONE) {}
	Element(Vector2 position) : position(position), dimensions(DEFAULT_DIMENSIONS), direction(NONE) {}
	Element(Vector2 position, Vector2 dimensions) : position(position), dimensions(dimensions), direction(NONE) {}
	int getX() const { return position.x(); }
	int getY() const { return position.y(); }
	int getWidth() const { return dimensions.x(); }
	int getHeight() const { return dimensions.y(); }
	Direction getDirection() const { return direction;}
	void setX(int x) { position.x(x); }
	void setY(int y) { position.y(y); }
	void setWidth(int width) { dimensions.x(width); }
	void setHeight(int height) { dimensions.y(height); }
	void setDirection(Direction direction) { this->direction = direction; }
	Vector2& getPosition() { return position; }
	void setPosition(Vector2 position) { setX(position.x()); setY(position.y()); }
};
