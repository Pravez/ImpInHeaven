#pragma once
#include "DataModifierComponent.h"

#define DEFAULT_INTERVAL

class TimeComponent : public DataModifierComponent
{
private:
	t_delta elapsed_time;
	t_delta interval;
	t_delta last_update;

public:
	TimeComponent() : interval(DEFAULT_INTERVAL) {}
	TimeComponent(t_delta interval) : interval(interval) {}
	~TimeComponent() {}


	void update(t_delta delta) override;
};
