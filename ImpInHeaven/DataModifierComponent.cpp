#include "DataModifierComponent.h"

void DataModifierComponent::setPositionX(int x) const
{
	this->getGameElement()->getPositionX() = x;
}

void DataModifierComponent::setPositionY(int y) const
{
	this->getGameElement()->getPositionY() = y;
}

void DataModifierComponent::setWidth(int width) const
{
	this->getGameElement()->getWidth() = width;
}

void DataModifierComponent::setHeight(int height) const
{
	this->getGameElement()->getHeight() = height;
}

void DataModifierComponent::setPosition(Vector2<int> position) const
{
	this->setPositionX(position.x());
	this->setPositionY(position.y());
}

void DataModifierComponent::setDirection(Direction direction) const
{
	this->getGameElement()->getDirection() = direction;
}

void DataModifierComponent::setListenerBoolean(bool val) const
{
	this->getGameElement()->getListenerBoolean() = val;
}
