#pragma once
#include "DataModifierComponent.h"


class AutonomousBehaviorComponent : public DataModifierComponent
{
private:
	Vector2<int> goal;
public:
	AutonomousBehaviorComponent() {}
	~AutonomousBehaviorComponent() {}

	void update(t_delta delta) override;
	GameEvent defineNextMovement() const;
};
