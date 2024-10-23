#pragma once
#include "Condition.hpp"
class IdleCondition : public Condition
{
public:
	IdleCondition();
	~IdleCondition();
	bool Test(Entity* Entity)override;
};

