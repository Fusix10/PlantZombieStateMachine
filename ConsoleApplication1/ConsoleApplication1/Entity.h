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
	sf::Sprite* mSprite;
public:
	int mRow;
	Entity();
	virtual ~Entity();
	void setState(Context::StateLabel State);
	Context::StateLabel getState() const;
	virtual void Init(sf::Vector2f position, Behaviour* behaviour, Context::StateLabel state, sf::Vector2f vector,int row);
	virtual void Update(/*sf::Vector2f position = {0,0}, sf::Vector2f vector = {0,0}, Context::StateLabel state = Context::StateLabel::Total, Behaviour* behaviour = nullptr, int row = NULL, sf::Sprite* sprite = nullptr*/) = 0;

	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
	sf::Sprite* GetSprite();

	void setPosition(sf::Vector2f New_Pos);

	int getRow();
	sf::Vector2f getVector();
};

