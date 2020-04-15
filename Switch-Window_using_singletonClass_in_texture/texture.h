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

    sf::Texture playerTexture;
    sf::Texture openMenuTexture;

    sf::Font openMenuFont;

public:
    static Texture* getInstace();
    ~Texture();

    sf::Texture* getPlayerTexture();
    sf::Texture* getOpenMenuTexture();

    sf::Font* getOpenMenuFont();
};