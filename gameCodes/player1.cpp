#include "player1.h"

#include "texture.h"

Player1::Player1()
{
    rect.setSize(sf::Vector2f(32, 32));
    sprite.setTexture(*(Texture::getInstace()->getPlayerRightTexture()));
    pos = sf::Vector2f(200, 500);

    hp = 50;
    healthBar.setFillColor(sf::Color::Green);

    this->walkSpeed=10.f;
    this->points = 0;
}

Player1::~Player1()
{
}

void Player1::Movimentation()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (pos.x >= 40))
    {
        speed.x = -walkSpeed;
        pos.x += speed.x;
        right = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (pos.x <= ((175 * 32) - 40)))
    {
        speed.x = walkSpeed;
        pos.x += speed.x;
        right = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        jump();

    adjustSprite();

    rect.setPosition(pos);
    sprite.setPosition(rect.getPosition());

    healthBar.setSize(sf::Vector2f(hp+(32*6), 20));
}

void Player1::drawPlayer1(sf::RenderWindow& window)
{
    healthBar.setPosition(rect.getPosition().x - 32*17, window.getSize().y - (window.getSize().y - 32*2));

    window.draw(sprite);
    window.draw(healthBar);
}

void Player1::adjustSprite()
{
    if (right)
        sprite.setScale(1,1);
    else
        sprite.setScale(-1,1);
}
