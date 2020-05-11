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

    sf::Texture player1Texture;
    sf::Texture player2Texture;
    sf::Texture openMenuTexture;
    sf::Texture splashScreenTexture;
    sf::Texture phase1;
    sf::Texture phase2;
    sf::Texture brickFloor;
    sf::Texture iceFloor;
    sf::Texture iceFloor2;
    sf::Texture purpleFloor;
    sf::Texture spike;

    sf::Font openMenuFont;

public:
    static Texture* getInstace();
    ~Texture();

    sf::Texture* getPlayerTexture();
    sf::Texture* getOpenMenuTexture();
    sf::Texture* getSplashScreenTexture();
    sf::Texture* getPhase1Texture();
    sf::Texture* getPhase2Texture();
    sf::Texture* getBrickFloor();
    sf::Texture* getIceFloor();
    sf::Texture* getIceFloor2();
    sf::Texture* getPurpleFloor();
    sf::Texture* getSpikeTrap();

    sf::Font* getOpenMenuFont();
};