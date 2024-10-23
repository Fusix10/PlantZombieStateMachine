#pragma once

#include "Context.hpp"
#include <map>
#include <vector>

class Action;
class Entity;
class Transition;

class Behaviour
{
    std::map<Context::StateLabel, std::vector<Action*>> mActions;
    std::map<Context::StateLabel, std::vector<Transition*>> mTransitions;
public:
    Behaviour();
    ~Behaviour();

    void Start(Entity *Entity);
    void Update(Entity *Entity);
    void End(Entity *Entity);

    void AddAction(Context::StateLabel key, Action* value);
    void AddTransition(Context::StateLabel key, Transition* value);
};
