#pragma once
#include "DataModifierComponent.h"
#include "Vector.hpp"

class MovementComponent : public DataModifierComponent
{
private:
	Vector2<int> speed;

public:
	MovementComponent() {}
	MovementComponent(Vector2<int> speed) : speed(speed) {}
	virtual ~MovementComponent() {}
	
	Vector2<int> getSpeed() const;
	void setSpeed(Vector2<int> speed);
	void applySpeedVector() const;
	void resetSpeedVector();

	void update() override;

	virtual void move();
};
