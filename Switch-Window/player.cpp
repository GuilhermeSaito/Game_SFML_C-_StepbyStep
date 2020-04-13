#include "player.h"

Player::Player()
{
    playerSprite.setTexture(*playerTexture.getTexture());
    playerSprite.setPosition(0,0);
}

Player::~Player()
{
}

/* USAR ESSE & É A MESMA COISA DO QUE EU USAR O * AQUI E & NA CHAMADA DA FUNÇÃO */
void Player::draw(sf::RenderWindow& window)
{
    window.draw(playerSprite);
}