#pragma once
#include "Entity.h"


class Plant : public Entity
{
    std::string mName;
    int mAmmoCount, mMaxAmmo;
public:
    Plant();
    ~Plant();

    void Init(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int row);

    void Update() override;


    int getAmmoCount() const;
    void refillMagazine() ;

    void shoot();

    
};
