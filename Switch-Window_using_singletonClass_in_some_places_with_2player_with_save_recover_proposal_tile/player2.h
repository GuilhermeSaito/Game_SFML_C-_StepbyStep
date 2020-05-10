#pragma once

#include "entity.h"

class Player2: public Entity
{
private:

public:
    Player2();
    ~Player2();

    void Movimentation();
    sf::Vector2f getPlayer2Position();
    void setPlayer2Position(sf::Vector2f p2);
    
    void drawPlayer2(sf::RenderWindow& window);
    void adjustSprite();
};