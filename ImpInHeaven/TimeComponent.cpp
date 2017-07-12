#include "TimeComponent.h"

void TimeComponent::update(t_delta delta)
{
	elapsed_time = delta - last_update;
	last_update = delta;

	if(elapsed_time >= interval)
	{
		addEvent(GameEvent(TIME, NO_ACTION));
	}
}
