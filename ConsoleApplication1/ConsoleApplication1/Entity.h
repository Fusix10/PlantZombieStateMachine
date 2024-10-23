#pragma once
#include <SFML/Graphics.hpp>
#include "Behaviour.hpp"
#include <iostream>

class Entity
{
protected:
	sf::Color mColor;
	sf::Vector2f mPosition;
	sf::Vector2f mVector;
	Context::StateLabel mState;
	Behaviour* mBehaviour;
	int mRow;
	sf::Sprite mSprite;
public:
	Entity();
	virtual ~Entity();
	void setState(Context::StateLabel State);
	Context::StateLabel getState() const;

	virtual void Update() = 0;

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
};

