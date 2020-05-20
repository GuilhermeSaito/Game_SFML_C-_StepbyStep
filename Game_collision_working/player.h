/*
    Todas as colisões com os player vão ser tratados aqui
*/

#pragma once

#include "texture.h"
#include "player1.h"
#include "player2.h"
#include "boss.h"

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

    bool player1OnGround;

public:
    static Player* getInstance();
    ~Player();

    void draw(sf::RenderWindow& window);

    void setIsMultiplayer(bool m);
    bool getIsMultiplayer();

    Player1* getPlayer1();
    Player2* getPlayer2();
};
