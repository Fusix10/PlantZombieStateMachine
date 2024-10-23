#include "ReloadingAction.h"
#include "Plant.hpp"

void ReloadingAction::Start(Entity* Entity)
{
	mTimeSpent = 0;
	mStartReloadingTimePoint = std::chrono::system_clock::now();
}

void ReloadingAction::Update(Entity* Entity)
{
	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
	mTimeSpent = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - mStartReloadingTimePoint).count();
	if (mTimeSpent >= 3000) {
		mTimeSpent = 0;
		dynamic_cast<Plant*>(Entity)->refillMagazine();
		Entity->setState(Context::StateLabel::Idle);
	}
}

void ReloadingAction::End(Entity* Entity)
{

}
