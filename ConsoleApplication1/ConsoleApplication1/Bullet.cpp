#include "Bullet.h"
#include "Garden.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
}

void Bullet::Init(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f vector, int row)
{
	Entity::Init(position, Garden::GetInstance()->GetBulletBehaviour(), Context::StateLabel::Moving, sf::Vector2f(1.f, 0.f), row);
	mSprite = new sf::Sprite();
	mSprite->setTexture(Garden::GetInstance()->mTexture);
	mSprite->setScale(sf::Vector2f(0.15f, 0.05f));
	mSprite->setPosition(position);
}

void Bullet::Update()
{
	mBehaviour->Update(this);
}
