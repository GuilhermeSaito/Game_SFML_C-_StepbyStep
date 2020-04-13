#include "texture.h"

Texture::Texture()
{
    if (!playerTexture.loadFromFile("Image.jpg"))
        EXIT_FAILURE;
    if (!openMenuTexture.loadFromFile("openMenuBackGround.jpg"))
        EXIT_FAILURE;
}

Texture::~Texture()
{
}

sf::Texture* Texture::getTexture()
{
    return &playerTexture;
}

sf::Texture* Texture::getOpenMenuTexture()
{
    return &openMenuTexture;
}