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
    mHp = 5;
    mPosition = position;
    mBehaviour = plant_behaviour;
    mAmmoCount = ammo_count;
    mMaxAmmo = mAmmoCount;
    mRow = row;
    mState = Context::StateLabel::Idle;
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
    Bullet* iBullet = new Bullet();
    iBullet->init(mPosition, mRow);
}

void Plant::Update()
{
}
