#pragma once
#include "GameComponent.h"

class DataModifierComponent : public GameComponent
{
protected:
	DataModifierComponent() {}
	DataModifierComponent(GameElement* element) : GameComponent(element) {}

	void setPositionX(int x) const;
	void setPositionY(int y) const;
	void setWidth(int width) const;
	void setHeight(int height) const;
	void setPosition(Vector2<int> position) const;
	void setDirection(Direction direction) const;
};
