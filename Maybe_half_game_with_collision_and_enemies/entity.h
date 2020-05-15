#pragma once

#include <SFML/Graphics.hpp>
#include "tile.h"
#include <vector>

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

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f pos);

    void jump();
    void gravity();

    void collideY(Tile* tile);
    void collideX(Tile* tile);
    sf::FloatRect getBoundBox();
};
