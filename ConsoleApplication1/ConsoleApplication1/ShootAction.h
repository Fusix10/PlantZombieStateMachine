#pragma once
#include "Action.hpp"
#include <chrono>
class ShootAction : public Action
{
private:
    double mTimeSpent;
    std::chrono::time_point<std::chrono::system_clock> mStartShootingTimePoint;
public:
    void Start(Entity* Entity) override;
    void Update(Entity* Entity) override;
    void End(Entity* Entity) override;
};

