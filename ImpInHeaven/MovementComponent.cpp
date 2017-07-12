#include "MovementComponent.h"

void MovementComponent::update(t_delta delta)
{
	Vector2<int> next_position;

	EVENT_INPUT_ACTION action;
	while((action = getEventAction(MOVEMENT, true)) != NO_ACTION)
	{
		switch (action)
		{
		case MOVE_UP: 
			next_position._y -= 1;
			break;
		case MOVE_DOWN: 
			next_position._y += 1;
			break;
		case MOVE_LEFT: 
			next_position._x -= 1;
			break;
		case MOVE_RIGHT: 
			next_position._x += 1;
			break;
		case NO_ACTION: break;
		default: ;
		}
	}

	move(next_position);
}

void MovementComponent::move(Vector2<int> to_position) const
{

	setPositionX(getPositionX() + to_position._x);
	setPositionY(getPositionY() + to_position._y);
}
