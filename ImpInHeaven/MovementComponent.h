#pragma once
#include "DataModifierComponent.h"
#include "Vector.hpp"

class MovementComponent : public DataModifierComponent
{
public:
	MovementComponent() {}
	virtual ~MovementComponent() {}

	void update() override;
	void move(Vector2<int> to_position) const;
};
