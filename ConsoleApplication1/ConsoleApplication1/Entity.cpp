#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setState(Context::StateLabel)
{
}

Context::StateLabel Entity::getState() const
{
	return Context::StateLabel();
}

sf::Color Entity::getColor() const
{
	return sf::Color();
}

sf::Vector2f Entity::getPosition() const
{
	return sf::Vector2f();
}
