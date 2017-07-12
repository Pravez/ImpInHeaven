#pragma once
#include "DataModifierComponent.h"

class EventListenerComponent : public DataModifierComponent
{
public:
	EventListenerComponent() {}

	void update(t_delta delta) override {}

	virtual void update(SDL_Event* event) = 0;
};
