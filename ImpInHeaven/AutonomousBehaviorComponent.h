#pragma once
#include "DataModifierComponent.h"

class AutonomousBehaviorComponent : public DataModifierComponent
{
public:
	AutonomousBehaviorComponent() {}
	~AutonomousBehaviorComponent() {}

	void update() override;
};
