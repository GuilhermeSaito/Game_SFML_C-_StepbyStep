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

    float jumpSpeed;
    float walkSpeed;
    float gravityAcceleration;
    bool right;

public:
    int hp;
    bool onGround;
    int points;

    Entity();
    ~Entity();

    bool getOnGround();
    void setOnGround(bool o);

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f p1);

    sf::Vector2f getSize();

    sf::FloatRect getBoundBox();

    void jump();
    void gravity();

    void collideY(Tile* tile);
    void collideX(Tile* tile);
};
