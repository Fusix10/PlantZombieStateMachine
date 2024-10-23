#pragma once

class Entity;

class Condition 
{
public:
    virtual bool Test(Entity* Entity) = 0;
};
