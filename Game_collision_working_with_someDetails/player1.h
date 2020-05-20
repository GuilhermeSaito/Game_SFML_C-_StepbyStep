#pragma once

#include "entity.h"

class Player1: public Entity
{
private:
    int attackDamage;
    sf::Text scoreText;
    int score;

public:
    Player1();
    ~Player1();

    void Movimentation();
    
    void drawPlayer1(sf::RenderWindow& window);
    void adjustSprite();

    bool playerDie();
    int getAttackDamage();
    void takeDamage(int d);

    void gainPoints(int p);
};