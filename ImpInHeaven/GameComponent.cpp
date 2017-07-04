#include "GameComponent.h"

void GameComponent::setGameElement(GameElement* element)
{
	this->element = element;
}

int GameComponent::getPositionX() const
{
	return getGameElement()->getPositionX();
}

int GameComponent::getPositionY() const
{
	return getGameElement()->getPositionY();
}

int GameComponent::getWidth() const
{
	return getGameElement()->getWidth();
}

int GameComponent::getHeight() const
{
	return getGameElement()->getHeight();
}

Vector2<int> GameComponent::getPosition() const
{
	return getGameElement()->getPosition();
}

Direction GameComponent::getDirection() const
{
	return getGameElement()->getDirection();
}

void GameComponent::addEvent(GameEvent event) const
{
	getGameElement()->addEvent(event);
}

EVENT_INPUT_ACTION GameComponent::getEventAction(EVENT_TYPE type, bool pop) const
{
	return getGameElement()->getValidatedEvent(type, pop);
}
