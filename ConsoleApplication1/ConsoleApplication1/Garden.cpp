#include "Garden.h"
#include "Plant.hpp"
#include "Zombie.h"
#include "Zombie.h"
namespace {
	static Garden* mInstance = nullptr;
}

void Garden::checkCollision(std::vector<Bullet*>& mProjectiles, std::vector<Zombie*>& mEnemies)
{
}

Garden::Garden()
{
}

Garden::~Garden()
{
}

Garden* Garden::Instantiate()
{
	if(mInstance == nullptr)
	{
		mInstance = new Garden();
	}
	return mInstance;
}

Garden* Garden::GetInstance()
{
	return mInstance;
}

void Garden::draw(sf::RenderWindow& window)
{
}

void Garden::update()
{
}

void Garden::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
}
