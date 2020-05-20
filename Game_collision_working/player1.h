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
};