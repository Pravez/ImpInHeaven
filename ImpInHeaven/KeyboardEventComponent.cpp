#include "KeyboardEventComponent.h"

void KeyboardEventComponent::update(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN) {
		switch (event->key.keysym.sym) {
		case SDLK_UP:
			addEvent(GameEvent(KEYBOARD_INPUT, MOVE_UP));
			break;
		case SDLK_DOWN:
			addEvent(GameEvent(KEYBOARD_INPUT, MOVE_DOWN));
			break;
		case SDLK_RIGHT:
			addEvent(GameEvent(KEYBOARD_INPUT, MOVE_RIGHT));
			break;
		case SDLK_LEFT:
			addEvent(GameEvent(KEYBOARD_INPUT, MOVE_LEFT));
			break;
		default:break;
		}
	}
}
