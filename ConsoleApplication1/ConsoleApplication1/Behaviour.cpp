#include "Behaviour.hpp"
#include "IdleAction.h"

#include "Plant.hpp"
#include "Transition.hpp"

Behaviour::Behaviour()
{
    //mActions = std::map<Context::StateLabel, std::vector<Action*>>();
    //mTransitions = std::map<Context::StateLabel, std::vector<Transition*>>();
}

Behaviour::~Behaviour()
{
    for (auto it : mTransitions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }

    for (auto it : mActions)
    {
        for (int i = 0; i < it.second.size(); ++i)
        {
            delete it.second[i];
        }
    }
}

void Behaviour::AddTransition(Context::StateLabel key, Transition* value)
{
    mTransitions[key].push_back(value);
}

void Behaviour::AddAction(Context::StateLabel key, Action* value)
{
    mActions[key].push_back(value);
}

void Behaviour::Start(Entity * Entity)
{
    for (const auto & a : mActions[Entity->getState()])
    {
        a->Start(Entity);
    }
}

void Behaviour::Update(Entity * Entity)
{
    for (const auto & a : mActions[Entity->getState()])
    {
        a->Update(Entity);
    }

    for (const auto & a : mTransitions[Entity->getState()])
    {
        a->Try(Entity);
    }
}


void Behaviour::End(Entity * Entity)
{
    for (const auto & a : mActions[Entity->getState()])
    {
        a->End(Entity);
    }
}

