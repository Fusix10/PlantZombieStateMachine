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
	std::vector<Plant*> mPlants;
	std::vector<Zombie*> mZombies;
	std::vector<Bullet*> mBullets;
	//std::vector<Entity*> mEntites;
	Behaviour* mPlantBehaviour;
	Behaviour* mZombieBehaviour;
	Behaviour* mBulletBehaviour;
	Garden();
	void checkCollision(
		std::vector<Bullet*>& mProjectiles,
		std::vector<Zombie*>& mEnemies);
	void checkCollision(
		std::vector<Plant*>& mPlants, std::vector<Zombie*>& mEnemies);
public:
	~Garden();
	void Init();
	sf::Texture mTexture;
	sf::Texture mTexture1;
	Plant* CreatePlant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int row);
	Zombie* CreateZombie(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f mVector, int row);
	Bullet* CreateBullet();
	static Garden* Instantiate();
	static Garden* GetInstance();
	void draw(sf::RenderWindow& window);
	void update();
	void handleUserInput(sf::Event& event, sf::RenderWindow&window);
	Behaviour* GetPlantBehaviour();
	Behaviour* GetZombieBehaviour();
	Behaviour* GetBulletBehaviour();
	std::vector<Plant*> GetPlants();
	std::vector<Zombie*> GetZombies();
	std::vector<Bullet*> GetBullets();
};

