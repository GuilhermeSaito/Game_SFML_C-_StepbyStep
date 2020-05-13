#pragma once

#include <SFML/Graphics.hpp>
#include "tile.h"

class Entity
{
protected:
    sf::RectangleShape rect;
    sf::RectangleShape healthBar;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f speed;
    sf::Vector2f pos;

    bool onGround;
    float jumpSpeed;
    float walkSpeed;
    float gravityAcceleration;
    bool right;

public:
    Entity();
    ~Entity();

    bool getOnGround();
    void setOnGround(bool o);

    void jump();
    void gravity();

    void collideY(Tile* tile);
    void collideX(Tile* tile);
};