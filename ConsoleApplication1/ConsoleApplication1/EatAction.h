#pragma once
#include "Action.hpp"
#include <chrono>
class EatAction : public Action
{
private:
    double mTimeSpent;
    std::chrono::time_point<std::chrono::system_clock> mStartEatingTimePoint;
public:
    void Start(Entity* Entity) override;
    void Update(Entity* Entity) override;
    void End(Entity* Entity) override;
};

