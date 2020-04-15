#pragma once

#include "texture.h"

class Player
{
private:
    sf::Sprite playerSprite;

public:
    Player();
    ~Player();

    void draw(sf::RenderWindow& window);
};