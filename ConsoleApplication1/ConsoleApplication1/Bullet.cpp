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
	Entity::Init(position, Garden::GetInstance()->GetBulletBehaviour(), Context::StateLabel::Moving, sf::Vector2f(0.f, 0.f), row);
}

void Bullet::Update()
{
	mBehaviour->Update(this);
}
