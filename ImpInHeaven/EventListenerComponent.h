#pragma once
#include "DataModifierComponent.h"

class EventListenerComponent : public DataModifierComponent
{
public:
	EventListenerComponent() {}

	void update() override {}

	virtual void update(SDL_Event* event) = 0;
};
