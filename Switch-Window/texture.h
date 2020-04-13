#pragma once

#include "library.h"

class Texture
{
private:
    sf::Texture playerTexture;
    sf::Texture openMenuTexture;

public:
    Texture();
    ~Texture();

    sf::Texture* getTexture();
    sf::Texture* getOpenMenuTexture();
};