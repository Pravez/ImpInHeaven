#pragma once
#include "Vector.hpp"

class Entity
{

private:
	Vector2 position;

public:
	Entity(int x, int y) : position(Vector2(x, y)) {};
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	Vector2& getPosition();
	void setPosition(Vector2 position);
};
