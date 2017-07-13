#pragma once
#include "EventListenerComponent.h"

class KeyboardEventComponent : public EventListenerComponent
{
public:
	KeyboardEventComponent() { }
	void update(SDL_Event* event) override;
};
