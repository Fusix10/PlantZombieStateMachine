#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Behaviour.hpp"
#include <iostream>

class Entity
{
protected:
	sf::Color mColor;
	sf::Vector2f mPosition;
	Context::StateLabel mState;
	Behaviour* mBehaviour;
	int mRow;
public:
	Entity();
	virtual ~Entity();
	void setState(Context::StateLabel State);
	Context::StateLabel getState() const;

	virtual void Update() = 0;

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
};

