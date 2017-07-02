#include "Entity.h"

Entity::Entity(Vector2<int> position) : position(position)
{
	//Bounds qualifies the real physic boundaries (for collisions ...)
	bounds.x = position.x() - DEFAULT_WIDTH/2;
	bounds.y = position.y() - DEFAULT_HEIGHT/2;
	bounds.w = DEFAULT_WIDTH;
	bounds.h = DEFAULT_HEIGHT;
}

Vector2<int> Entity::getPosition() const
{
	return position;
}

SDL_Rect Entity::getBounds() const
{
	return bounds;
}

void Entity::setBounds(int x, int y, int width, int height)
{
	bounds.x = x;
	bounds.y = y;
	bounds.x = width;
	bounds.h = height;
}

void Entity::setPosition(Vector2<int> position)
{
	this->position.x(position.x());
	this->position.y(position.y());
}

void Entity::setPositionX(int x)
{
	this->position.x(x);
}

void Entity::setPositionY(int y)
{
	this->position.y(y);
}
