/*
    Singleton class, just to be sure that this class will be instantiated only once;
*/


#pragma once

#include "library.h"

class Texture
{
private:
    Texture();
    Texture(Texture const&);
    static Texture* t_instance;

    sf::Texture playerRightTexture;
    sf::Texture openMenuTexture;
    sf::Texture splashScreenTexture;
    sf::Texture phase1;
    sf::Texture phase2;
    sf::Texture brickFloor;
    sf::Texture iceFloor;
    sf::Texture iceFloor2;
    sf::Texture purpleFloor;
    sf::Texture spike;
    sf::Texture projectile;
    sf::Texture enemy1Texture;
    sf::Texture enemy1TextureRight;
    sf::Texture enemy2Texture;
    sf::Texture enemy2TextureRight;
    sf::Texture finalBossTexture;
    sf::Texture finalBossTextureLeft;

    sf::Font openMenuFont;

public:
    static Texture* getInstace();
    ~Texture();

    sf::Texture* getPlayerRightTexture();
    sf::Texture* getOpenMenuTexture();
    sf::Texture* getSplashScreenTexture();
    sf::Texture* getPhase1Texture();
    sf::Texture* getPhase2Texture();
    sf::Texture* getBrickFloor();
    sf::Texture* getIceFloor();
    sf::Texture* getIceFloor2();
    sf::Texture* getPurpleFloor();
    sf::Texture* getSpikeTrap();
    sf::Texture* getProjectileTexture();
    sf::Texture* getEnemy1Texture();
    sf::Texture* getEnemy1TextureRight();
    sf::Texture* getEnemy2Texture();
    sf::Texture* getEnemy2TextureRight();
    sf::Texture* getFinalBossTexture();
    sf::Texture* getFinalBossTextureLeft();

    sf::Font* getOpenMenuFont();
};
