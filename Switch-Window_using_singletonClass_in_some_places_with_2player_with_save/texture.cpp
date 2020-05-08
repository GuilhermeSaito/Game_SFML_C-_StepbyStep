#include "texture.h"

// Global static pointer to ensure a singleton class
Texture* Texture::t_instance = NULL;


Texture::Texture()
{
    if (!player1Texture.loadFromFile("mario.png"))
        EXIT_FAILURE;
    if (!openMenuTexture.loadFromFile("splash.png"))
        EXIT_FAILURE;
    if (!openMenuFont.loadFromFile("font1.ttf"))
        EXIT_FAILURE;
    if (!splashScreenTexture.loadFromFile("splashScreen.jpg"))
        EXIT_FAILURE;
    if (!phase1.loadFromFile("phase1.png"))
        EXIT_FAILURE;
    if (!phase2.loadFromFile("phase2.png"));
        EXIT_FAILURE;

    phase1.setRepeated(true);
    
}

Texture::~Texture()
{
}

Texture* Texture::getInstace()
{
    if (!t_instance)
        t_instance = new Texture;
    return t_instance;
}

sf::Texture* Texture::getPlayerTexture()
{
    return &player1Texture;
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

sf::Font* Texture::getOpenMenuFont()
{
    return &openMenuFont;
}