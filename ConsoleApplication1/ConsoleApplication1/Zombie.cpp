#include "Zombie.h"
#include "Plant.hpp"
#include "Garden.h"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::Init(sf::Vector2f position, Behaviour* zombie_behaviour, sf::Vector2f vector,int row)
{
    Entity::Init(position, zombie_behaviour, Context::StateLabel::Moving, vector,row);
    mSprite = new sf::Sprite();
    mSprite->setTexture(Garden::GetInstance()->mTexture1);
    mSprite->setScale(sf::Vector2f(0.15f, 0.08f));
    mSprite->setPosition(position);
}


void Zombie::Update()
{
    mBehaviour->Update(this);
}

void Zombie::Eat(Plant* plant)
{
    plant->mHp--;
    if (plant->mHp <= 0) {
        delete plant;
    }
}
