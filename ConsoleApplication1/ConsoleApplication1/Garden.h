#pragma once

#include "SFML/Graphics.hpp"

class Plant;
class Zombie;
class Bullet;
class Entity;

class Garden
{
private:
	std::vector<Plant*> mPlants;
	std::vector<Zombie*> mZombies;
	std::vector<Bullet*> mBullets;
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

