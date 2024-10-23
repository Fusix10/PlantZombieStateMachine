#pragma once

#include "Context.hpp"
#include "Condition.hpp"

#include <vector>

class Entity;

class Transition
{
protected:
    Context::StateLabel mTargetState;
    std::vector<Condition*> mConditions;

public:
    void Try(Entity* Entity);
    void setTargetState(Context::StateLabel target_state);
    void addCondition(Condition* condition);
};
