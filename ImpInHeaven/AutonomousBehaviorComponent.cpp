#include "AutonomousBehaviorComponent.h"

void AutonomousBehaviorComponent::update(t_delta delta)
{
	while(getEventAction(TIME, true) != NO_ACTION)
	{
		if(goal != getPosition())
		{
			addEvent(defineNextMovement());
		} else
		{
			goal = Vector2<int>(rand() % 15, rand() % 15);
		}
	}
}

GameEvent AutonomousBehaviorComponent::defineNextMovement() const
{
	if (goal._x < getPositionX())
		return GameEvent(MOVEMENT, MOVE_LEFT);
	if (goal._x > getPositionX())
		return GameEvent(MOVEMENT, MOVE_RIGHT);
	if (goal._y < getPositionY())
		return GameEvent(MOVEMENT, MOVE_UP);
	if (goal._y > getPositionY())
		return GameEvent(MOVEMENT, MOVE_DOWN);

	return GameEvent(MOVEMENT, NO_ACTION);
}
