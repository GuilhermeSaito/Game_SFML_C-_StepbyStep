#pragma once

#include "entity.h"

class Player1: public Entity
{
private:

public:
    Player1();
    ~Player1();

    void Movimentation();
    
    void drawPlayer1(sf::RenderWindow& window);
    void adjustSprite();

    void collision();

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f p1);

    sf::Vector2f getSize();

    void setIsOnFloor(bool y);

    void playerCollisionFloor();

    sf::FloatRect getBoundBox();
};