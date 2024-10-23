#pragma once

#include "SFML/Graphics.hpp"

class Plant;
class Zombie;
class Bullet;
class Entity;
class Behaviour;

class Garden
{
private:
	//std::vector<Plant*> mPlants;
	//std::vector<Zombie*> mZombies;
	//std::vector<Bullet*> mBullets;
	std::vector<Entity*> mEntites;
	Behaviour* mPlantBehaviour;
	Behaviour* mZombieBehaviour;
	Behaviour* mBulletBehaviour;
	Garden();
	void checkCollision(
		std::vector<Bullet*>& mProjectiles,
		std::vector<Zombie*>& mEnemies);
public:
	~Garden();
	void Init();
	sf::Texture mTexture;
	Plant* CreatePlant();
	Zombie* CreateZombie();
	Bullet* CreateBullet();
	static Garden* Instantiate();
	static Garden* GetInstance();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&
		window);

};

