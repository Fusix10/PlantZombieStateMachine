#include "EatCondition.h"
#include "Garden.h"
#include "Zombie.h"
EatCondition::EatCondition()
{
}

EatCondition::~EatCondition()
{
}

bool EatCondition::Test(Entity* Entity)
{
	std::vector<Plant*> test = Garden::GetInstance()->GetPlants();
	if (Garden::GetInstance()->checkCollisionEat(test, dynamic_cast<Zombie*>(Entity))) {
		return true;
	}
	return false;
}
