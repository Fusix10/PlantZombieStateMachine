#pragma once
#include "Plant.hpp"
#include "Zombie.h"
class Garden
{
private:
	std::vector<Plant*> mPlants;
	std::vector<std::vector<Zombie*>> mZombies;
};

