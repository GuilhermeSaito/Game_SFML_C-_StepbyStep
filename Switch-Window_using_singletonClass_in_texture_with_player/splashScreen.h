#pragma once

#include "switchWindow.h"
#include "texture.h"

class SplashScreen: public SwitchWindow
{
private:
    sf::Sprite sprite;

public:
    SplashScreen();
    ~SplashScreen(); 

    int Start(sf::RenderWindow& window) override;   
};