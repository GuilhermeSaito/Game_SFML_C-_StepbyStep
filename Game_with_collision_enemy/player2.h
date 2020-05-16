#pragma once

#include "entity.h"

class Player2: public Entity
{
private:

public:
    Player2();
    ~Player2();

    void Movimentation();
    
    void drawPlayer2(sf::RenderWindow& window);
    void adjustSprite();

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f p2);

    sf::Vector2f getPlayerSize();

    void setIsOnFloor(bool y);

    sf::FloatRect getBoundBox();
};