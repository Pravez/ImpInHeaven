#include "GameElement.h"
#include "DataAccessorComponent.h"
#include "DataModifierComponent.h"
#include "EventListenerComponent.h"

GameElement::GameElement()
{
	this->position = Vector2<int>(0, 0);
	init();
}

GameElement::GameElement(const Vector2<int> position) : position(position), listener(false)
{
	init();
}

GameElement::~GameElement()
{
}

void GameElement::init()
{
	this->direction = NONE;
	this->width = DEFAULT_WIDTH;
	this->height = DEFAULT_HEIGHT;
	this->state = ALIVE;
	this->accessorComponents = {};
	this->modifierComponents = {};
	this->events = {};
	this->validatedEvents = {};
}

int & GameElement::getPositionX()
{
	return position._x;
}

int & GameElement::getPositionY()
{
	return position._y;
}

int & GameElement::getWidth()
{
	return width;
}

int & GameElement::getHeight()
{
	return height;
}

Vector2<int>& GameElement::getPosition()
{
	return position;
}

Direction & GameElement::getDirection()
{
	return direction;
}

State& GameElement::getState()
{
	return state;
}

bool& GameElement::getListenerBoolean()
{
	return listener;
}

bool GameElement::hasEventListener() const
{
	return listener;
}

void GameElement::setPositionX(int x)
{
	position._x = x;
}

void GameElement::setPositionY(int y)
{
	position._y = y;
}

void GameElement::setWidth(int width)
{
	this->width = width;
}

void GameElement::setHeight(int height)
{
	this->height = height;	
}

void GameElement::setPosition(Vector2<int> position)
{
	this->position._x = position.x();
	this->position._y = position.y();
}

void GameElement::setDirection(Direction direction)
{
	this->direction = direction;
}

void GameElement::setState(State state)
{
	this->state = state;
}

DataAccessorComponent* GameElement::addAccessorComponent(DataAccessorComponent* component)
{
	this->accessorComponents.push_back(component);
	return component;
}

DataModifierComponent* GameElement::addModifierComponent(DataModifierComponent* component)
{
	this->modifierComponents.push_back(component);
	return component;
}

EventListenerComponent* GameElement::setEventListener(EventListenerComponent* eventListener)
{
	this->eventListener = eventListener;
	return eventListener;
}

void GameElement::addEvent(GameEvent event)
{
	events.push(event);
}

bool GameElement::hasEvent() const
{
	return !events.empty();
}

GameEvent GameElement::popEvent()
{
	GameEvent event = events.front();
	events.pop();
	return event;
}

void GameElement::handleEvents(SDL_Event* event)
{
	if(hasEventListener())
	{
		eventListener->update(event);
	}
}

void GameElement::updateModifiers(t_delta delta)
{
	for (auto mc : modifierComponents)
	{
		mc->update(delta);
	}
}

void GameElement::updateAccessors(t_delta delta)
{
	for (auto ac : accessorComponents)
	{
		ac->update(delta);
	}
}

void GameElement::validateEvent(GameEvent event)
{
	this->validatedEvents.insert(std::pair<EVENT_TYPE, EVENT_INPUT_ACTION>(event.type, event.input_action));
}

EVENT_INPUT_ACTION GameElement::getValidatedEvent(EVENT_TYPE key, bool pop)
{
	if (this->validatedEvents.find(key) != this->validatedEvents.end()) {
		if (this->validatedEvents.count(key) > 0) {
			EVENT_INPUT_ACTION action = (*this->validatedEvents.begin()).second;
			if (pop)
			{
				this->validatedEvents.erase(this->validatedEvents.begin());
			}

			return action;
		}
	}

	return NO_ACTION;
}
