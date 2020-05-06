#include "player.h"

Player* Player::p_instance = NULL;

Player::Player()
{
}

Player::~Player()
{
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
}

void Player::setIsMultiplayer(bool m)
{
    isMultiplayer = m;
}