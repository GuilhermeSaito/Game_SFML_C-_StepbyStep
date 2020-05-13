#include "player1.h"

#include "texture.h"
#include "collisionManager.h"

Player1::Player1() 
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setFillColor(sf::Color::White);

    pos = sf::Vector2f(200, 500);
}

Player1::~Player1()
{
}

void Player1::Movimentation()
{
    gravity();
    /*cout << "On ground: " << onGround << endl
         << "Gravity Speed: " << gravitySpeed << endl
         << "Pos(y): " << pos.y << endl
         << "Speed(y): " << speed.y << endl;*/

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (pos.x >= 40))
    {
        speed.x = -walkSpeed;
        pos.x += speed.x;
        right = false;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (pos.x <= ((175 * 32) - 40)))
    {
        speed.x = walkSpeed;
        pos.x += speed.x;
        right = true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump();

    adjustSprite();
}

void Player1::drawPlayer1(sf::RenderWindow& window)
{
    rect.setPosition(pos);
    sprite.setPosition(rect.getPosition());
    window.draw(rect);
}

void Player1::adjustSprite()
{
    if (right)         
        sprite.setTexture(*(Texture::getInstace()->getPlayerRightTexture()));
    else               
        sprite.setTexture(*(Texture::getInstace()->getPlayerLeftTexture()));
}

sf::Vector2f Player1::getPosition()
{
    return pos;
}

void Player1::setPosition(sf::Vector2f p1)
{
    pos = p1;
}

sf::Vector2f Player1::getSize()
{
    return rect.getSize();
}

void Player1::setIsOnFloor(bool y)
{
    this->onGround = y;
}

sf::FloatRect Player1::getBoundBox()
{
    return sf::FloatRect(pos.x, pos.y, rect.getSize().x, rect.getSize().y);
}