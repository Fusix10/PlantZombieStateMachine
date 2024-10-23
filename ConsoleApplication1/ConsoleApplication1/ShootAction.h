#pragma once
#include "Action.hpp"
class ShootAction : public Action
{
public:
    void Start(Entity* Entity) override;
    void Update(Entity* Entity) override;
    void End(Entity* Entity) override;
};

