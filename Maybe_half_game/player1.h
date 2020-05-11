#pragma once

#include "entity.h"

class Player1: public Entity
{
private:

public:
    Player1();
    ~Player1();

    void Movimentation();
    sf::Vector2f getPlayer1Position();
    void setPlayer1Position(sf::Vector2f p1);
    
    void drawPlayer1(sf::RenderWindow& window);
    void adjustSprite();
};