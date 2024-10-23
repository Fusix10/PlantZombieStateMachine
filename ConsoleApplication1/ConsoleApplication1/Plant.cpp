#include "Plant.hpp"
#include "Bullet.h"
#include "Garden.h"

Plant::Plant()
{
    
}

Plant::~Plant()
{
}

void Plant::Init(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count,int row)
{
    Entity::Init(position, plant_behaviour, Context::StateLabel::Idle,sf::Vector2f(0.f,0.f),row);
    mHp = 5;
    mAmmoCount = ammo_count;
    mMaxAmmo = mAmmoCount;
    mSprite =new sf::Sprite();
    mSprite->setTexture(Garden::GetInstance()->mTexture);
    mSprite->setScale(sf::Vector2f(0.15f, 0.05f));
    mSprite->setPosition(position);
}

int Plant::getAmmoCount() const
{
    return mAmmoCount;
}

void Plant::refillMagazine()
{
    mAmmoCount = mMaxAmmo;
}

void Plant::shoot()
{
    Garden::GetInstance()->CreateBullet(mPosition, Garden::GetInstance()->GetBulletBehaviour(),sf::Vector2f(1.f,0.f),mRow);
}

void Plant::Update()
{
    mBehaviour->Update(this);
}
