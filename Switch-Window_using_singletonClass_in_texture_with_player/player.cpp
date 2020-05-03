#include "player.h"

Player::Player()
{
    playerSprite.setTexture(*(Texture::getInstace()->getPlayerTexture()));
    pos = sf::Vector2f(0, 300);
    acceleration = sf::Vector2f(0.5, 1);
    speed = sf::Vector2f(10, 0);
    maxSpeed = sf::Vector2f(20, 1);
    playerSprite.setPosition(0, 300);
    friction = 0.75;
}

Player::~Player()
{
}

/* USAR ESSE & É A MESMA COISA DO QUE EU USAR O * AQUI E & NA CHAMADA DA FUNÇÃO */
void Player::draw(sf::RenderWindow& window)
{
    playerSprite.setPosition(pos);
    window.draw(playerSprite);
}

// NEED TO FUX THE JUMP (POSITION ON Y)
void Player::PlayerMovimentation(sf::RenderWindow& window)
{
    //Input for movement testing:
    sf::Vector2f currentAcc = sf::Vector2f(0,0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        currentAcc.x = -acceleration.x;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        currentAcc.x = acceleration.x;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        currentAcc.y = acceleration.y;

    //Gravity
    if(pos.y < 0) // Maximum hight that can go
        currentAcc.y += 1;  // Vellocity that will fall
    else //touching invisible floor
    {
        pos.y = 300; //dont let the player fall through floor
        speed.y = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            currentAcc.y = -acceleration.y;
    }

    speed += currentAcc;
    //limits the vertical and horizontal maxSpeed of the player
    if(speed.x > maxSpeed.x)
        speed.x = maxSpeed.x;
    if(speed.x < -maxSpeed.x)
        speed.x = -maxSpeed.x;
    if(speed.y > maxSpeed.y)
        speed.y = maxSpeed.y;
    if(speed.y < -maxSpeed.y)
        speed.y = -maxSpeed.y;

    //applies friction
    speed *= friction;

    //change entity's position
    pos += speed;

    //setView(window);

    draw(window);
}

// NEET TO FIX THIS, THE PROBLEM IS THAT, WHEN ESC IS PRESSED, THE VISION OF THE VINDOW DISAJUST
void Player::setView(sf::RenderWindow& window)
{
    playerView.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    //playerView.setCenter(sf::Vector2f(playerView.getSize().x/2, playerView.getSize().y/2));
    window.setView(playerView);
    playerView.setCenter(playerSprite.getPosition());
}