#pragma once
#include "Action.hpp"
#include <chrono>
class ReloadingAction : public Action
{
public:
    double mTimeSpent;
    std::chrono::time_point<std::chrono::system_clock> mStartReloadingTimePoint;
    void Start(Entity* Entity)override;
    void Update(Entity* Entity)override;
    void End(Entity* Entity)override;
};

