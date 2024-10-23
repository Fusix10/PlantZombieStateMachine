#pragma once
#include "Entity.h"
class Zombie : public Entity
{
public:
	Zombie();
	~Zombie();
	void init(sf::Vector2f position, int row);
};

