#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
    Bullet();
    ~Bullet();
    void init(sf::Vector2f position, int row);
    void Update() override;
    int GetSpeed();
};

