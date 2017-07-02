#pragma once
#include "Entity.h"
#include "Direction.h"

class MoveableEntity : public Entity
{
private:
	Direction direction;
	Vector2<int> speed;
	
public:
	MoveableEntity(Vector2<int> position);
	Direction getDirection() const;
	Vector2<int> getSpeed() const;

	void setDirection(Direction direction);
	void setSpeed(Vector2<int> speed);

	void update() override;
	virtual void applyMovement();
};
