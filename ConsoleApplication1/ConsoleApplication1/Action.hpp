#pragma once

class Entity;

class Action
{
public:
    virtual void Start(Entity * Entity) = 0;
    virtual void Update(Entity * Entity) = 0;
    virtual void End(Entity * Entity) = 0;
};
