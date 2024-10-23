#pragma once
#include "Entity.h"
class Plant;
class Zombie : public Entity
{
public:
	Zombie();
	~Zombie();
	void Init(sf::Vector2f position, Behaviour* zombie_behaviour,sf::Vector2f mVector, int row);
	void Update() override;
	void Eat(Plant* plant);
};

