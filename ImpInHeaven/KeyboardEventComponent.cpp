#include "KeyboardEventComponent.h"

void KeyboardEventComponent::update(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN) {
		switch (event->key.keysym.sym) {
		case SDLK_UP:
			addEvent(GameEvent(MOVEMENT, MOVE_UP));
			break;
		case SDLK_DOWN:
			addEvent(GameEvent(MOVEMENT, MOVE_DOWN));
			break;
		case SDLK_RIGHT:
			addEvent(GameEvent(MOVEMENT, MOVE_RIGHT));
			break;
		case SDLK_LEFT:
			addEvent(GameEvent(MOVEMENT, MOVE_LEFT));
			break;
		default:break;
		}
	}
}

void KeyboardEventComponent::setListenerBoolTrue() const
{
	this->getGameElement()->getListenerBoolean() = true;
}
