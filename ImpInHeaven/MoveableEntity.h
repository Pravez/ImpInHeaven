#pragma once
#include "Entity.h"
#include "Direction.h"

class MoveableEntity : public Entity
{
private:
	Direction direction;
	Vector2 speed;
	
public:
	MoveableEntity(Vector2 position);
	Direction getDirection() const;
	Vector2 getSpeed() const;

	void setDirection(Direction direction);
	void setSpeed(Vector2 speed);

	void update() override;
	virtual void applyMovement();
};
