#include "Zombie.h"
#include "Garden.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(sf::Vector2f position, int row)
{
		mBehaviour = Garden::GetInstance()->GetBulletBehaviour();
		mPosition = position;
		mRow = row;
}
