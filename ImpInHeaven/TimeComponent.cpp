#include "TimeComponent.h"
#include <iostream>

void TimeComponent::update(t_delta delta)
{
	elapsed_time = elapsed_time + delta;

	if(elapsed_time >= interval)
	{
		std::cout << "Time event triggered" << std::endl;
		addEvent(GameEvent(TIME, TIMER_ALERT));
		elapsed_time = elapsed_time - interval;
	}
}
