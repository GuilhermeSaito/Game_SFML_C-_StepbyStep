#include "player.h"

Player* Player::p_instance = NULL;

Player::Player()
{
    player1Pos = sf::Vector2f(0, 500);
    player2Pos = sf::Vector2f(10, 500);
}

Player::~Player()
{
    delete p_instance;
}

Player* Player::getInstance()
{
    if (!p_instance)
        p_instance = new Player;
    return p_instance;
}

/* USAR ESSE & É A MESMA COISA DO QUE EU USAR O * AQUI E & NA CHAMADA DA FUNÇÃO */
void Player::draw(sf::RenderWindow& window)
{    
    playerView.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    playerView.setCenter(player1Pos);
    window.setView(playerView);
    if (isMultiplayer)
    {
        player1.Movimentation();
        player1.drawPlayer1(window);
        player2.Movimentation();
        player2.drawPlayer2(window);
    }
    else
    {
        player1.Movimentation();
        player1.drawPlayer1(window);
    }
    player1Pos = player1.getPlayer1Position();
    player2Pos = player2.getPlayer2Position();
}

/************************************************************/

void Player::setIsMultiplayer(bool m)
{
    isMultiplayer = m;
}

bool Player::getIsMultiplayer()
{
    return isMultiplayer;
}

/************************************************************/

void Player::setPlayer1Position(sf::Vector2f p1)
{
    player1Pos = p1;
    player1.setPlayer1Position(player1Pos);
}

void Player::setPlayer2Position(sf::Vector2f p2)
{
    player2Pos = p2;
    player2.setPlayer2Position(p2);
}

sf::Vector2f Player::getPlayer1Position()
{
    return player1Pos;
}

sf::Vector2f Player::getPlayer2Position()
{
    return player2Pos;
}

/************************************************************/

void Player::setPlayer1Name(std::string p1)
{
    player1Name = p1;
}

void Player::setPlayer2Name(std::string p2)
{
    player2Name = p2;
}

std::string Player::getPlayer1Name()
{
    return player1Name;
}

std::string Player::getPlayer2Name()
{
    return player2Name;
}