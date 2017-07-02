#include "MovementComponent.h"

Vector2<int> MovementComponent::getSpeed() const
{
	return speed;
}

void MovementComponent::setSpeed(Vector2<int> speed)
{
	this->speed = speed;
}

void MovementComponent::applySpeedVector() const
{
	if (speed._x != 0 || speed._y != 0) {
		int x = getPositionX(), y = getPositionY();

		setPositionX(x + speed._x);
		setPositionY(y + speed._y);
	}

	//Direction must be changed here, instead of in-update
}

void MovementComponent::resetSpeedVector()
{
	speed._x = 0;
	speed._y = 0;
}


void MovementComponent::update()
{
	EVENT_INPUT_ACTION action;
	while((action = getEventAction(KEYBOARD_INPUT, true)) != NO_ACTION)
	{
		switch (action)
		{
		case MOVE_UP: 
			speed._y = speed._y < 1 ? speed._y + 1 : speed._y;
			setDirection(NORTH);
			break;
		case MOVE_DOWN: 
			speed._y = speed._y > -1 ? speed._y - 1 : speed._y;
			setDirection(SOUTH);
			break;
		case MOVE_LEFT: 
			speed._x = speed._x > -1 ? speed._x - 1 : speed._x;
			setDirection(WEST);
			break;
		case MOVE_RIGHT: 
			speed._x = speed._x < 1 ? speed._x + 1 : speed._x;
			setDirection(EAST);
			break;
		case NO_ACTION: break;
		default: ;
		}
	}

	move();
}

void MovementComponent::move()
{
	applySpeedVector();
	resetSpeedVector();
}
