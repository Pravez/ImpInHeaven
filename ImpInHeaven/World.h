﻿#pragma once
#include <vector>
#include "GameElement.h"
#include "Map.hpp"

class World
{
private:
	Map* map;
	std::vector<GameElement*> entities;

public:
	World();
	void addElement(GameElement* entity);
	void update();

	void handleEvent(SDL_Event* event);
	void handleElementEventsQueue(GameElement* entity) const;

	bool validateMovement(GameElement* entity, EVENT_INPUT_ACTION movement) const;
	bool checkInBounds(Vector2<int> position) const;

	void setMap(Map* map);
};
