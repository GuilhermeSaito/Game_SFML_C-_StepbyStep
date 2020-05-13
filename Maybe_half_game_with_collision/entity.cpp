#include "entity.h"

Entity::Entity()
{
    speed = sf::Vector2f(0, 0);
    gravityAcceleration = 1.1;
    jumpSpeed = -150;
    walkSpeed = 10;
    onGround = false;
}

Entity::~Entity()
{
}

bool Entity::getOnGround()
{
    return onGround;
}

void Entity::setOnGround(bool o)
{
    onGround = o;
}

void Entity::jump()
{
    if (onGround)
    {
        pos.y += jumpSpeed;
        onGround = false;
    }
}


void Entity::gravity()
{
    if (!onGround)
    {
        speed.y += gravityAcceleration;
        pos.y += speed.y;
        onGround = false;
    }
}

// Se speedY > 0    =   CAINDO
// Se speedY < 0    =   SUBINDO
void Entity::collideY(Tile* tile)
{
    if (speed.y > 0)
    {
        pos.y = tile->getBoundBox().top - rect.getSize().y;
        onGround = true;
    }
    else if (speed.y < 0)
        pos.y = tile->getBoundBox().top + tile->getBoundBox().height;
    speed.y = 0;
}

void Entity::collideX(Tile* tile)
{
    if (speed.x > 0)
        pos.x = tile->getBoundBox().left - rect.getSize().x;
    else if (speed.y < 0)
        pos.x = tile->getBoundBox().left + tile->getBoundBox().width;
    speed.x = 0;
}