#pragma once
#include "Condition.hpp"
class EatCondition : public Condition
{
public:
	EatCondition();
	~EatCondition();
	bool Test(Entity* Entity)override;
};

