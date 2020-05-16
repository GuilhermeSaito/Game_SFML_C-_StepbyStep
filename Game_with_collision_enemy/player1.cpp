#include "player1.h"

#include "texture.h"

Player1::Player1() 
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setFillColor(sf::Color::White);

    sprite.setTexture(*(Texture::getInstace()->getPlayerRightTexture()));

    pos = sf::Vector2f(200, 500);
}

Player1::~Player1()
{
}

void Player1::Movimentation()
{
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
    window.draw(sprite);
}

void Player1::adjustSprite()
{
    if (right)         
        sprite.setScale(1,1);
    else               
        sprite.setScale(-1,1);
}
