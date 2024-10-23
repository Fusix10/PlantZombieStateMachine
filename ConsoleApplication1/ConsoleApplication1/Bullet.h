#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
    Bullet();
    ~Bullet();
    void Init(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f vector, int row);
    void Update() override;
};

