#include "MovementAction.h"
#include "Entity.h"

void MovementAction::Start(Entity* Entity)
{

}

void MovementAction::Update(Entity* Entity)
{
	sf::Vector2f Pos;
	Pos.x = Entity->getVector().x * 0.005f;
	Pos.y = Entity->getVector().y * 0.005f;
	Entity->setPosition(Pos);
}

void MovementAction::End(Entity* Entity)
{
}
