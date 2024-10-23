#include "ShootCondition.h"
#include "Garden.h"
#include "Zombie.h"

ShootCondition::ShootCondition()
{
}

ShootCondition::~ShootCondition()
{
}

bool ShootCondition::Test(Entity* Entity)
{
	for (int i = 0; i < Garden::GetInstance()->GetZombies().size(); i++) {
		if (Garden::GetInstance()->GetZombies()[i]->mRow == Entity->mRow) {
			return true;
		}
	}
	return false;
}
