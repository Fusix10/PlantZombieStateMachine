#include "Plant.hpp"
#include "Bullet.h"
Plant::Plant()
{
}


Plant::~Plant()
{
}

void Plant::Init(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count)
{
    mPosition = position;
    mBehaviour = plant_behaviour;
    mAmmoCount = ammo_count;
    mMaxAmmo = mAmmoCount;
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
    
}

void Plant::Update()
{
}
