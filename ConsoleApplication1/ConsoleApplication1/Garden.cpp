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
namespace {
	static Garden* mInstance = nullptr;
}

void Garden::checkCollision(std::vector<Bullet*>& mProjectiles, std::vector<Zombie*>& mEnemies)
{
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
	mPlantBehaviour = new Behaviour();
	mZombieBehaviour = new Behaviour();
	mBulletBehaviour = new Behaviour();

	mPlantBehaviour->AddAction(Context::StateLabel::Shooting, SA);
	mPlantBehaviour->AddAction(Context::StateLabel::Idle, IA);
	mPlantBehaviour->AddAction(Context::StateLabel::Reloading, RA);

	mZombieBehaviour->AddAction(Context::StateLabel::Idle, IA);
	mZombieBehaviour->AddAction(Context::StateLabel::Moving, MA);
	mZombieBehaviour->AddAction(Context::StateLabel::Eating, EA);

	mBulletBehaviour->AddAction(Context::StateLabel::Moving, MA);
	
	if (!mTexture.loadFromFile("../jogo.png")) {

	}

}
Plant* Garden::CreatePlant()
{
	return new Plant();
}
Zombie* Garden::CreateZombie()
{
	return new Zombie();
}
Bullet* Garden::CreateBullet()
{
	return new Bullet();
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
