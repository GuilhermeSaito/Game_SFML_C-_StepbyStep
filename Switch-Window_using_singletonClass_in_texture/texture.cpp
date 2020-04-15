#include "texture.h"

// Global static pointer to ensure a singleton class
Texture* Texture::t_instance = NULL;


Texture::Texture()
{
    if (!playerTexture.loadFromFile("Image.jpg"))
        EXIT_FAILURE;
    if (!openMenuTexture.loadFromFile("openMenuBackGround.jpg"))
        EXIT_FAILURE;
    if (!openMenuFont.loadFromFile("font1.ttf"))
        EXIT_FAILURE;
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
    return &playerTexture;
}

sf::Texture* Texture::getOpenMenuTexture()
{
    return &openMenuTexture;
}

sf::Font* Texture::getOpenMenuFont()
{
    return &openMenuFont;
}