#pragma once

enum EVENT_TYPE { MOVEMENT, MOUSE_INPUT };
enum EVENT_INPUT_ACTION { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT, NO_ACTION };

struct GameEvent
{
	GameEvent(EVENT_TYPE type, EVENT_INPUT_ACTION action) : type(type), input_action(action) {}
	EVENT_TYPE type;
	EVENT_INPUT_ACTION input_action;
};
