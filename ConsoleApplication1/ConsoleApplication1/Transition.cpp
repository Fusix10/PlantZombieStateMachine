#include "Transition.hpp"
#include "Plant.hpp"

void Transition::setTargetState(Context::StateLabel target_state)
{
    mTargetState = target_state;
}

void Transition::addCondition(Condition* condition)
{
    mConditions.push_back(condition);
}

void Transition::Try(Entity* Entity)
{
    int true_tests = 0;
    for (const auto &c : mConditions)
    {
        true_tests += c->Test(Entity);
    }
    if (true_tests != 0 && true_tests == mConditions.size())
    {
        Entity->setState(mTargetState);
    }
}
