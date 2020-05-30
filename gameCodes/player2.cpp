#include "player2.h"

#include "texture.h"

Player2::Player2()
{
    //sprite.setTexture(*(Texture::getInstace()->getPlayerTexture()));
    sprite.setScale(sf::Vector2f(1.5, 1.5));

    rect.setSize(sf::Vector2f(64, 64));

    pos = sf::Vector2f(64, 500);
    speed = sf::Vector2f(10, 1);

    onGround = true;
}

Player2::~Player2()
{
}

void Player2::Movimentation()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        pos.x -= speed.x;
        right = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        pos.x += speed.x;
        right = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        jump();

    adjustSprite();
}

void Player2::drawPlayer2(sf::RenderWindow& window)
{
    sprite.setPosition(pos);
    window.draw(this->sprite);
}

void Player2::adjustSprite()
{
    //if (right)          // width: 0 to 50, hight: 32 to 64*2
        //sprite.setTextureRect(sf::IntRect(0, 64*2, 64, 64));
    //else                // width: 0 to 50, hight: 64*3 to 64*4
        //sprite.setTextureRect(sf::IntRect(0, 64, 64, 64));
}

sf::Vector2f Player2::getPosition()
{
    return pos;
}

void Player2::setPosition(sf::Vector2f p2)
{
    pos = p2;
}

sf::Vector2f Player2::getPlayerSize()
{
    return rect.getSize();
}

void Player2::setIsOnFloor(bool y)
{
    this->onGround = y;
}

sf::FloatRect Player2::getBoundBox()
{
    return sf::FloatRect(pos.x, pos.y, rect.getSize().x, rect.getSize().y);
}