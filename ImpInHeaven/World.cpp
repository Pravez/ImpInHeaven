#include "World.h"

World::World()
{

}

void World::addElement(GameElement* element)
{
	this->entities.push_back(element);
}

void World::update()
{
	for (auto element : entities)
	{
		handleElementEventsQueue(element);
		element->updateModifiers();
	}

	for(auto element : entities)
	{
		element->updateAccessors();
	}
}

void World::handleEvent(SDL_Event* event)
{
	for (auto element : entities)
	{
		if (element->hasEventListener())
		{
			element->handleEvents(event);
		}
	}
}

void World::handleElementEventsQueue(GameElement* element) const
{
	while(element->hasEvent())
	{
		GameEvent event = element->popEvent();
		switch (event.type)
		{
		case KEYBOARD_INPUT:
			if (validateMovement(element, event.input_action))
			{
				element->validateEvent(event);
			}
		case MOUSE_INPUT: 
			break;
		default: ;
		}
	}
}

bool World::validateMovement(GameElement* element, EVENT_INPUT_ACTION movement) const
{
	Vector2<int> position = Vector2<int>(element->getPosition());

	switch(movement)
	{
	case MOVE_UP: 
		position._y += 1;
		break;
	case MOVE_DOWN: 
		position._y -= 1;
		break;
	case MOVE_LEFT: 
		position._x -= 1;
		break;
	case MOVE_RIGHT: 
		position._x += 1;
		break;
	case NO_ACTION: break;
	default: ;
	}

	if(checkInBounds(position))
	{
		if(!map->isWall(position))
		{
			if (map->isTrap(position))
			{
				element->setState(DEAD);
			}

			return true;
		}
	}

	return false;
}

bool World::checkInBounds(Vector2<int> position) const
{
	return position.x() < map->getWidth() && position.x() > 0 && position.y() < map->getHeight() && position.y() > 0;
}

void World::setMap(Map* map)
{
	this->map = map;
}
