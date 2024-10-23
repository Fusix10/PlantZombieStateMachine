#include "EatAction.h"

void EatAction::Start(Entity* Entity)
{
	mTimeSpent = 0;
	mStartEatingTimePoint = std::chrono::system_clock::now();
}

void EatAction::Update(Entity* Entity)
{
	std::chrono::time_point<std::chrono::system_clock> currentTime = std::chrono::system_clock::now();
	mTimeSpent = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - mStartEatingTimePoint).count();
	if (mTimeSpent >= 3000) {
		mTimeSpent = 0;
		Entity->setState(Context::StateLabel::Idle);
	}
}

void EatAction::End(Entity* Entity)
{
}
