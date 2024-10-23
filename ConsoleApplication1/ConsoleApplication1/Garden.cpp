#include "Garden.h"
#include "Plant.hpp"
#include "Zombie.h"
#include "Bullet.h"
#include "Behaviour.hpp"
#include "ShootAction.h"
#include "EatAction.h"
#include "MovementAction.h"
#include "IdleAction.h"
#include "ReloadingAction.h"
#include "EatCondition.h"
#include "EatAction.h"
#include "IdleCondition.h"
#include "ShootCondition.h"
#include "transition.hpp"
namespace {
	static Garden* mInstance = nullptr;
}

void Garden::checkCollision(std::vector<Bullet*>& mProjectiles, std::vector<Zombie*>& mEnemies)
{
	for (int I = 0; I < mProjectiles.size(); I++) 
	{
		for (int II = 0; II < mEnemies.size(); II++)
		{
			if (mProjectiles[I]->getRow() == mEnemies[II]->getRow() && mProjectiles[I]->getPosition().x + 10 >= mEnemies[II]->getPosition().x && mProjectiles[I]->getPosition().x + 10 <= mEnemies[II]->getPosition().x + 50) 
			{

				auto it = std::find(mProjectiles.begin(), mProjectiles.end(), mProjectiles[I]);

				if (it != mProjectiles.end()) {
					delete* it;        // Delete the object pointed to by the iterator
					mProjectiles.erase(it);    // Remove the pointer from the vector
				}
				auto it2 = std::find(mEnemies.begin(), mEnemies.end(), mEnemies[I]);

				if (it2 != mEnemies.end()) {
					delete* it2;        // Delete the object pointed to by the iterator
					mEnemies.erase(it2);    // Remove the pointer from the vector
				}
			}
		}
	}
}

void Garden::checkCollision(std::vector<Plant*>& mPlants, std::vector<Zombie*>& mEnemies)
{
	//state zombie 
	for (int I = 0; I < mPlants.size(); I++)
	{
		for (int II = 0; II < mEnemies.size(); II++)
		{
			if (mPlants[I]->getRow() == mEnemies[II]->getRow() && mPlants[I]->getPosition().x + 10 >= mEnemies[II]->getPosition().x && mPlants[I]->getPosition().x + 10 <= mEnemies[II]->getPosition().x + 50)
			{
				mEnemies[II]->setState(Context::StateLabel::Eating);
			}
		}
	}
}

Garden::Garden()
{
}
void Garden::Init()
{
	ShootAction* SA = new ShootAction();
	IdleAction* IA = new IdleAction();
	MovementAction* MA = new MovementAction();
	EatAction* EA = new EatAction();
	ReloadingAction* RA = new ReloadingAction();


	ShootCondition* SC = new ShootCondition();
	IdleCondition* IC = new IdleCondition();
	EatCondition* EC = new EatCondition();

	Transition* Transition1 = new Transition();
	Transition1->addCondition(SC);
	Transition1->setTargetState(Context::StateLabel::Shooting);
	Transition* Transition2 = new Transition();
	Transition2->addCondition(IC);
	Transition2->setTargetState(Context::StateLabel::Idle);
	Transition* Transition3 = new Transition();
	Transition3->addCondition(EC);
	Transition3->setTargetState(Context::StateLabel::Eating);


	mPlantBehaviour = new Behaviour();
	mZombieBehaviour = new Behaviour();
	mBulletBehaviour = new Behaviour();



	mPlantBehaviour->AddAction(Context::StateLabel::Shooting, SA);
	mPlantBehaviour->AddAction(Context::StateLabel::Idle, IA);
	mPlantBehaviour->AddAction(Context::StateLabel::Reloading, RA);
	mPlantBehaviour->AddTransition(Context::StateLabel::Idle, Transition1);
	mPlantBehaviour->AddTransition(Context::StateLabel::Shooting, Transition2);

	mZombieBehaviour->AddAction(Context::StateLabel::Idle, IA);
	mZombieBehaviour->AddAction(Context::StateLabel::Moving, MA);
	mZombieBehaviour->AddAction(Context::StateLabel::Eating, EA);
	mZombieBehaviour->AddTransition(Context::StateLabel::Moving, Transition3);


	mBulletBehaviour->AddAction(Context::StateLabel::Moving, MA);

	
	if (!mTexture.loadFromFile("../jogo.png")) {

	}
	if (!mTexture1.loadFromFile("../suguna.png")) {

	}
}
Plant* Garden::CreatePlant(sf::Vector2f position, Behaviour* plant_behaviour, int ammo_count, int row)
{
	Plant* plant = new Plant();
	plant->Init(position, plant_behaviour, ammo_count, row);
	mPlants.push_back(plant);

	return plant;
}
Zombie* Garden::CreateZombie(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f mVector, int row)
{
	Zombie* zombie = new Zombie();
	zombie->Init(position, zombie_behaviour, mVector, row);
	mZombies.push_back(zombie);
	return zombie;
}
Bullet* Garden::CreateBullet(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f mVector, int row)
{
	Bullet* bullet = new Bullet();
	bullet->Init(position, zombie_behaviour , mVector, row);
	mBullets.push_back(bullet);
	return bullet;
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
	for (int i = 0; i < mPlants.size(); i++) {
		mPlants[i]->Update();
		
	}
	for (int i = 0; i < mZombies.size(); i++) {
		mZombies[i]->Update();
	}
	for (int i = 0; i < mBullets.size(); i++) {
		mBullets[i]->Update();
	}
	checkCollision(mPlants, mZombies);
	checkCollision(mBullets, mZombies);
}

void Garden::handleUserInput(sf::Event& event, sf::RenderWindow& window)
{
}

Behaviour* Garden::GetPlantBehaviour()
{
	return mPlantBehaviour;
}

Behaviour* Garden::GetZombieBehaviour()
{
	return mZombieBehaviour;
}

Behaviour* Garden::GetBulletBehaviour()
{
	return mBulletBehaviour;
}

std::vector<Plant*> Garden::GetPlants()
{
	return mPlants;
}

std::vector<Zombie*> Garden::GetZombies()
{
	return mZombies;
}

std::vector<Bullet*> Garden::GetBullets()
{
	return mBullets;
}
