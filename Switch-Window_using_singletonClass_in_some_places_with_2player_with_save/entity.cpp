#include "entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::jump(bool& ground, sf::Vector2f& speed, sf::Vector2f& pos)
{
    if (ground)
    {
        pos.y -= speed.y;
        ground = false;
    }
}