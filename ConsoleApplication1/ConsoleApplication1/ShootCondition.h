#pragma once
#include "Condition.hpp"
class ShootCondition : public Condition
{
public:
	ShootCondition();
	~ShootCondition();
	bool Test(Entity* Entity)override;
};

