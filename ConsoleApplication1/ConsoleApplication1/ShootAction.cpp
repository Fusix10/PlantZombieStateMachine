#include "ShootAction.h"
#include "Plant.hpp"
void ShootAction::Start(Entity* Entity)
{
	mTimeSpent = 0;
	mStartShootingTimePoint = std::chrono::system_clock::now();
	dynamic_cast<Plant*>(Entity)->shoot();
}

void ShootAction::Update(Entity* Entity)
{
	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
	mTimeSpent = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - mStartShootingTimePoint).count();
	if (mTimeSpent >= 3000) {
		mTimeSpent = 0;
		Entity->setState(Context::StateLabel::Idle);
	}
}

void ShootAction::End(Entity* Entity)
{

}
