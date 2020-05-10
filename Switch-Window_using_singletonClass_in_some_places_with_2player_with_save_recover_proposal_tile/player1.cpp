#include "player1.h"

#include "texture.h"

Player1::Player1()
{
    sprite.setTexture(*(Texture::getInstace()->getPlayerTexture()));
    sprite.setScale(sf::Vector2f(1.5, 1.5));
    pos = sf::Vector2f(0, 500);
    speed = sf::Vector2f(1, 1);
    onGround = true;
}

Player1::~Player1()
{
}

void Player1::Movimentation()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pos.x -= speed.x;
        right = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pos.x += speed.x;
        right = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump(onGround, speed, pos);

    adjustSprite();
}

sf::Vector2f Player1::getPlayer1Position()
{
    return pos;
}

void Player1::setPlayer1Position(sf::Vector2f p1)
{
    pos = p1;
}

void Player1::drawPlayer1(sf::RenderWindow& window)
{
    sprite.setPosition(pos);
    window.draw(this->sprite);
}

void Player1::adjustSprite()
{
    if (right)          // width: 0 to 50, hight: 32 to 64*2
        sprite.setTextureRect(sf::IntRect(0, 64*2, 64, 64));
    else                // width: 0 to 50, hight: 64*3 to 64*4
        sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
}