#include "Entity.h"

int Entity::getX() const
{
	return position.x();
}	

int Entity::getY() const
{
	return position.y();
}

void Entity::setX(int x)
{
	position.x(x);
}

void Entity::setY(int y)
{
	position.y(y);
}

Vector2& Entity::getPosition()
{
	return position;
}

void Entity::setPosition(Vector2 position)
{
	this->position.x(position.x());
	this->position.y(position.y());
}

