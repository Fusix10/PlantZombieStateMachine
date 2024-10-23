#include "Entity.h"

Entity::Entity()
{
	mPosition = sf::Vector2f();
	mBehaviour = nullptr;
}

Entity::~Entity()
{
}

void Entity::setState(Context::StateLabel State)
{
	mState = State;
}

Context::StateLabel Entity::getState() const
{
	return mState;
}

void Entity::Init(sf::Vector2f position, Behaviour* behaviour, Context::StateLabel state, sf::Vector2f vector, int row)
{
	mPosition = position;
	mBehaviour = behaviour;
	mRow = row;
	mState = state;
	mVector = vector;
}



sf::Color Entity::getColor() const
{
	return mColor;
}

sf::Vector2f Entity::getPosition() const
{
	return mPosition;
}

sf::Sprite* Entity::GetSprite()
{
	return mSprite;
}
void Entity::setPosition(sf::Vector2f New_Pos)
{
	mPosition = mPosition + New_Pos;
	mSprite->setPosition(mPosition);
}

sf::Vector2f Entity::getVector()
{
	return mVector;
}
