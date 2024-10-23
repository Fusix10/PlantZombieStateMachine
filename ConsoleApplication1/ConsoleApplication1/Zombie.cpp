#include "Zombie.h"
#include "Plant.hpp"
#include "Garden.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::Init(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f mVector,int row)
{
    mPosition = position;
    mBehaviour = zombie_behaviour;
    mRow = row;
    mState = Context::StateLabel::Idle;
    mSprite = new sf::Sprite();
    mSprite->setTexture(Garden::GetInstance()->mTexture1);
    mSprite->setScale(sf::Vector2f(0.15f, 0.08f));
    mSprite->setPosition(position);
}

void Zombie::Update()
{
}

void Zombie::Eat(Plant* plant)
{
    plant->mHp--;
    if (plant->mHp <= 0) {
        delete plant;
    }
}
