#pragma once
#include "Vector.hpp"
#include "Direction.h"
#include <vector>
#include <SDL.h>
#include <queue>
#include "GameEvent.h"
#include <map>
#include "State.h"
#include "ChronoService.h"


#define DEFAULT_WIDTH 50
#define DEFAULT_HEIGHT 80

class DataAccessorComponent;
class DataModifierComponent;
class EventListenerComponent;


class GameElement
{
private:
	Vector2<int> position;
	int width;
	int height;

	Direction direction;
	State state;
	std::vector<DataAccessorComponent*> accessorComponents;
	std::vector<DataModifierComponent*> modifierComponents;

	std::vector<EventListenerComponent*> listeners;

	std::queue<GameEvent> events;
	std::multimap<EVENT_TYPE, EVENT_INPUT_ACTION> validatedEvents;

public:
	GameElement();
	GameElement(const Vector2<int> position);
	virtual ~GameElement();

	void init();
	
	int & getPositionX();
	int & getPositionY();
	int & getWidth();
	int & getHeight();
	Vector2<int> & getPosition();
	Direction & getDirection();
	State & getState();

	bool hasEventListener() const;

	void setPositionX(int x);
	void setPositionY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setPosition(Vector2<int> position);
	void setDirection(Direction direction);
	void setState(State state);

	DataAccessorComponent* addAccessorComponent(DataAccessorComponent* component);
	DataModifierComponent* addModifierComponent(DataModifierComponent* component);
	EventListenerComponent* addEventListener(EventListenerComponent* eventListener);

	void addEvent(GameEvent event);
	bool hasEvent() const;
	GameEvent popEvent();
	void validateEvent(GameEvent event);
	EVENT_INPUT_ACTION getValidatedEvent(EVENT_TYPE key, bool pop);

	virtual void updateModifiers(t_delta delta);
	virtual void updateAccessors(t_delta delta);
	virtual void handleEvents(SDL_Event* event);
};
