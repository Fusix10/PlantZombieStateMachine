#include "Bullet.h"
#include "Garden.h"

Bullet::Bullet()
{
	Garden::GetInstance();
}

Bullet::~Bullet()
{
}

void Bullet::init(sf::Vector2f position, int row)
{
	mRow = row;
}

void Bullet::Update()
{
}
