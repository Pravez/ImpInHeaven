#pragma once
#include "DataModifierComponent.h"

#define DEFAULT_INTERVAL std::chrono::seconds(1)

class TimeComponent : public DataModifierComponent
{
private:
	t_delta elapsed_time;
	t_delta interval;
	t_delta last_update;

public:
	TimeComponent() : interval(DEFAULT_INTERVAL), elapsed_time(std::chrono::seconds(0)) {}
	TimeComponent(t_delta interval) : interval(interval), elapsed_time(std::chrono::seconds(0)) {}
	~TimeComponent() {}


	void update(t_delta delta) override;
};
