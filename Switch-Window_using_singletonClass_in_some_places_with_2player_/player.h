#pragma once

#include "texture.h"
#include "player1.h"
#include "player2.h"

class Player
{
private:
    Player();
    Player(const Player&);
    static Player* p_instance;

    bool isMultiplayer;

    // Setting the vision on the player
    sf::View playerView;
    Player1 player1;
    Player2 player2;

public:
    static Player* getInstance();
    ~Player();

    void draw(sf::RenderWindow& window);

    void jump();
    void setIsMultiplayer(bool m);
};
