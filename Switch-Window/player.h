#pragma once

#include "texture.h"

class Player
{
private:
    sf::Sprite playerSprite;
    Texture playerTexture;

public:
    Player();
    ~Player();

    void draw(sf::RenderWindow& window);
};