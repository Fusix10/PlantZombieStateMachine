#include "Bullet.h"
#include "Garden.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
}

void Bullet::init(sf::Vector2f position, int row)
{
	mPosition = position; 
	mRow = row;
	mState = Context::StateLabel::Moving;
	mBehaviour = Garden::GetInstance()->GetBulletBehaviour();
}

void Bullet::Update()
{
}

int Bullet::GetSpeed()
{
	return mSpeed;
}
