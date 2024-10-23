#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Behaviour.hpp"
#include <iostream>

class Entity
{
public:
	sf::Vector2f mPosition;
	Context::StateLabel mState;
	Behaviour* mBehaviour;
public:
	Entity();
	virtual ~Entity();
	void setState(Context::StateLabel);
	Context::StateLabel getState() const;

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
};

