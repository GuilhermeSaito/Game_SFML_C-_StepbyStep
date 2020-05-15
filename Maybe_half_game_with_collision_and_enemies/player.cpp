#include "player.h"

Player* Player::p_instance = NULL;

Player::Player()
{
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
#include "collisionManager.h"
/* USAR ESSE & É A MESMA COISA DO QUE EU USAR O * AQUI E & NA CHAMADA DA FUNÇÃO */
void Player::draw(sf::RenderWindow& window)
{
    playerView.setSize(sf::Vector2f(window.getSize().x*2, window.getSize().y*2));
    playerView.setCenter(player1.getPosition());
    window.setView(playerView);

    // Evitar dele ficar andando em uma coisa q n existe.
    //if (!(CollisionManager::getInstance()->objectCollideGroundY()) && (player1.getOnGround()))
    //    player1.setOnGround(false);

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

Player1* Player::getPlayer1()
{
    return& player1;
}

Player2* Player::getPlayer2()
{
    return& player2;
}
