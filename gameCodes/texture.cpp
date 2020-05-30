#include "texture.h"

// Global static pointer to ensure a singleton class
Texture* Texture::t_instance = NULL;


Texture::Texture()
{
    if (!playerRightTexture.loadFromFile("player_right.png"))
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
    if (!projectile.loadFromFile("projectileTexture.png"))
        EXIT_FAILURE;
    if (!enemy1Texture.loadFromFile("enemy1Texture.png"))
        EXIT_FAILURE;
    if (!enemy1TextureRight.loadFromFile("enemy1TextureRight.png"))
        EXIT_FAILURE;
    if (!enemy2Texture.loadFromFile("enemy2Texture.png"))
        EXIT_FAILURE;
    if (!enemy2TextureRight.loadFromFile("enemy2TextureRight.png"))
        EXIT_FAILURE;
    if (!finalBossTexture.loadFromFile("finalBossTexture.png"))
        EXIT_FAILURE;
    if (!finalBossTextureLeft.loadFromFile("finalBossTextureLeft.png"))
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
    return &playerRightTexture;
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

sf::Texture* Texture::getProjectileTexture()
{
  return &projectile;
}

sf::Texture* Texture::getEnemy1Texture()
{
  return &enemy1Texture;
}

sf::Texture* Texture::getEnemy1TextureRight()
{
  return &enemy1TextureRight;
}

sf::Texture* Texture::getEnemy2Texture()
{
  return &enemy2Texture;
}

sf::Texture* Texture::getEnemy2TextureRight()
{
  return &enemy2TextureRight;
}

sf::Texture* Texture::getFinalBossTexture()
{
  return &finalBossTexture;
}

sf::Texture* Texture::getFinalBossTextureLeft()
{
  return &finalBossTextureLeft;
}

sf::Font* Texture::getOpenMenuFont()
{
    return &openMenuFont;
}
