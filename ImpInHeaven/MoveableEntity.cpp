#include "MoveableEntity.h"

MoveableEntity::MoveableEntity(Vector2 position) : Entity(position)
{
	direction = NORTH;
	speed = Vector2(0, 0);
}

Direction MoveableEntity::getDirection() const
{
	return direction;
}

Vector2 MoveableEntity::getSpeed() const
{
	return speed;
}

void MoveableEntity::setDirection(Direction direction)
{
	this->direction = direction;
}

void MoveableEntity::setSpeed(Vector2 speed)
{
	this->speed.x(speed.x());
	this->speed.y(speed.y());
}

void MoveableEntity::update()
{
	applyMovement();
}

void MoveableEntity::applyMovement()
{
	setPositionX(getPosition().x() + speed.x());
	setPositionY(getPosition().y() + speed.y());
}


