#include "MovementAction.h"
#include "Entity.h"

void MovementAction::Start(Entity* Entity)
{

}

void MovementAction::Update(Entity* Entity)
{
	sf::Vector2f Pos;
	Pos.x = Entity->getVector().x * 10;
	Pos.y = Entity->getVector().y * 10;
	Entity->setPosition(Pos);
}

void MovementAction::End(Entity* Entity)
{
}
