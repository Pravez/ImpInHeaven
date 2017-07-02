#pragma once
#include "GameElement.h"

class GameComponent
{
private:
	GameElement* element;

protected:
	virtual GameElement* getGameElement() const { return element; };

public:
	GameComponent() : element(nullptr) {}
	GameComponent(GameElement* element) : element(element) {}
	virtual ~GameComponent(){}

	void setGameElement(GameElement* element);

	int getPositionX() const;
	int getPositionY() const;
	int getWidth() const;
	int getHeight() const;
	Vector2<int> getPosition() const;
	Direction getDirection() const;

	void addEvent(GameEvent event) const;
	EVENT_INPUT_ACTION getEventAction(EVENT_TYPE type, bool pop) const;
	virtual void update() = 0;
};
