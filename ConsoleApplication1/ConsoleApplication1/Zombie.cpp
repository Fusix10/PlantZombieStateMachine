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

void Zombie::Eat()
{
    mTarget->mHp--;
    if (mTarget->mHp <= 0) {
        std::vector<Plant*>& test = Garden::GetInstance()->GetPlants();
        auto it = std::find(test.begin(), test.end(), mTarget);

        if (it != test.end()) {
            delete* it;        // Delete the object pointed to by the iterator
            test.erase(it);    // Remove the pointer from the vector
        }
    }
}
