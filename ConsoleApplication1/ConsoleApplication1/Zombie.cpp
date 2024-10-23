#include "Zombie.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::Init(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f vector,int row)
{
	mPosition = position;
	mBehaviour = zombie_behaviour;
	mVector = vector;
	mRow = row;
}

void Zombie::Update()
{
}
