#include "Plant.hpp"
#include "Bullet.h"

Plant::Plant()
{
    
}

Plant::~Plant()
{
}

void Plant::Init(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count,int row)
{
    mPosition = position;
    mBehaviour = plant_behaviour;
    mAmmoCount = ammo_count;
    mMaxAmmo = mAmmoCount;
    mRow = row;
    mState = Context::StateLabel::Idle;
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
