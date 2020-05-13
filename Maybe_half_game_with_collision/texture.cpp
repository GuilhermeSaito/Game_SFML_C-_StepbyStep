#include "texture.h"

// Global static pointer to ensure a singleton class
Texture* Texture::t_instance = NULL;


Texture::Texture()
{
    if (!player1TextureRight.loadFromFile("player_right.png"))
        EXIT_FAILURE;
    if (!player1TextureLeft.loadFromFile("player_left.png"))
        EXIT_FAILURE;
    if (!openMenuTexture.loadFromFile("splash.png"))
        EXIT_FAILURE;
    if (!openMenuFont.loadFromFile("font1.ttf"))
        EXIT_FAILURE;
    if (!splashScreenTexture.loadFromFile("splashScreen.jpg"))
        EXIT_FAILURE;
    if (!phase1.loadFromFile("phase1.png"))
        EXIT_FAILURE;
    if (!phase2.loadFromFile("phase2.png"))
        EXIT_FAILURE;
    if (!brickFloor.loadFromFile("BrickFloor.jpg"))
        EXIT_FAILURE;
    if (!iceFloor.loadFromFile("IceFloor.jpg"))
        EXIT_FAILURE;
    if (!iceFloor2.loadFromFile("IceFloor2.jpg"))
        EXIT_FAILURE;
    if (!purpleFloor.loadFromFile("PurpleFloor.jpg"))
        EXIT_FAILURE;
    if (!spike.loadFromFile("spikeTrap.jpg"))
        EXIT_FAILURE;

    phase1.setRepeated(true);
    
}

Texture::~Texture()
{
    delete t_instance;
}

Texture* Texture::getInstace()
{
    if (!t_instance)
        t_instance = new Texture;
    return t_instance;
}

sf::Texture* Texture::getPlayerRightTexture()
{
    return &player1TextureRight;
}

sf::Texture* Texture::getPlayerLeftTexture()
{
    return &player1TextureLeft;
}

sf::Texture* Texture::getOpenMenuTexture()
{
    return &openMenuTexture;
}

sf::Texture* Texture::getSplashScreenTexture()
{
    return &splashScreenTexture;
}

sf::Texture* Texture::getPhase1Texture()
{
    return &phase1;
}

sf::Texture* Texture::getPhase2Texture()
{
    return &phase2;
}

sf::Texture* Texture::getBrickFloor()
{
    return &brickFloor;
}

sf::Texture* Texture::getIceFloor()
{
    return &iceFloor;
}

sf::Texture* Texture::getIceFloor2()
{
    return &iceFloor2;
}

sf::Texture* Texture::getPurpleFloor()
{
    return &purpleFloor;
}

sf::Texture* Texture::getSpikeTrap()
{
    return &spike;
}

sf::Font* Texture::getOpenMenuFont()
{
    return &openMenuFont;
}