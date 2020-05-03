#pragma once

#include "texture.h"

class Player
{
private:
    sf::Sprite playerSprite;
    sf::Vector2f pos;
    sf::Vector2f acceleration;
    sf::Vector2f speed;
    sf::Vector2f maxSpeed;

    float friction;

    // Setting the vision on the player
    sf::View playerView;

public:
    Player();
    ~Player();

    void draw(sf::RenderWindow& window);
    void PlayerMovimentation(sf::RenderWindow& window);
    void setView(sf::RenderWindow& window);
};