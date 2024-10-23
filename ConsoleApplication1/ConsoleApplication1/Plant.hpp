#pragma once
#include "Entity.h"


class Plant : public Entity
{
    std::string mName;
    int mAmmoCount, mMaxAmmo;
public:
    Plant();
    Plant(
        sf::Vector2f position,
        Behaviour* plant_behaviour,
        int ammo_count);
    ~Plant();

    int getAmmoCount() const;
    void refillMagazine() ;

    bool shoot();

    void Update();
};
