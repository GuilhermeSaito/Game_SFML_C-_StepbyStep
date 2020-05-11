/*
    The Players Position is storage, temporarity, here;
*/

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

    sf::Vector2f player1Pos;
    sf::Vector2f player2Pos;
    std::string player1Name;
    std::string player2Name;

public:
    static Player* getInstance();
    ~Player();

    void draw(sf::RenderWindow& window);

    void jump();
    void setIsMultiplayer(bool m);
    bool getIsMultiplayer();

    void setPlayer1Position(sf::Vector2f p1);
    void setPlayer2Position(sf::Vector2f p2);
    sf::Vector2f getPlayer1Position();
    sf::Vector2f getPlayer2Position();

    void setPlayer1Name(std::string p1);
    void setPlayer2Name(std::string p2);
    std::string getPlayer1Name();
    std::string getPlayer2Name();
};
