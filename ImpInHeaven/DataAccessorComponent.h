#pragma once
#include "GameComponent.h"

class DataAccessorComponent : public GameComponent
{
private:
//	GameElement getGameElement() const override { return getGameElement(); };

public:
	DataAccessorComponent() {}
	DataAccessorComponent(GameElement* element) : GameComponent(element) {}
	virtual ~DataAccessorComponent() {}
};
