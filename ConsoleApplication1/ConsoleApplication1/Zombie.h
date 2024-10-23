#pragma once
#include "Entity.h"
class Zombie : public Entity
{
public:
	Zombie();
	~Zombie();
	void Init(sf::Vector2f position, Behaviour* zombie_behaviour, int ammo_count, sf::Vector2f mPosition,sf::Vector2f mVector);
	void Update() override;
};

