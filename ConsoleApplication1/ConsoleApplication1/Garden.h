#pragma once
#include "Plant.hpp"
#include "Zombie.h"
#include "SFML/Graphics.hpp"

namespace {
	static Garden* mInstance = nullptr;
}
class Garden
{
private:
	std::vector<Plant*> mPlants;
	std::vector<Zombie*> mZombies;
	std::vector<Bullet*> mZombies;
	std::vector<Entity*> mEntites;
	Garden();
	void checkCollision(
		std::vector<Bullet*>& mProjectiles,
		std::vector<Zombie*>& mEnemies);
public:
	~Garden();

	static Garden* Instantiate();
	static Garden* GetInstance();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);

};

