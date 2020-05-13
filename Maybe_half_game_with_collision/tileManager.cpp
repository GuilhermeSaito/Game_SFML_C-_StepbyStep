#include "tileManager.h"

#include "texture.h"

TileManager* TileManager::instance = nullptr;

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
    delete instance;
}

TileManager* TileManager::getInstance()
{
    if (!instance)
        instance = new TileManager;
    return instance;
}

sf::Texture* TileManager::getTileTexture(int tileType, sf::RectangleShape& rect, int spaceOcupedX, int spaceOcupedY)
{
    int spaceDefaultX = spaceOcupedX * 32;
    int spaceDefaultY = spaceOcupedY * 32;
    switch (tileType)
    {
    case BrickFloor:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(sf::Vector2f(spaceOcupedX, spaceOcupedY));
        return Texture::getInstace()->getBrickFloor();
        break;
    case IceFloor:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(sf::Vector2f(spaceOcupedX, spaceOcupedY));
        return Texture::getInstace()->getIceFloor();
        break;
    case IceFloor2:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(sf::Vector2f(spaceOcupedX, spaceOcupedY));
        return Texture::getInstace()->getIceFloor2();
        break;
    case PurpleFloor:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(sf::Vector2f(spaceOcupedX, spaceOcupedY));
        return Texture::getInstace()->getPurpleFloor();
        break;
    case Spike:
        rect.setSize(sf::Vector2f(32, 32));
        rect.setPosition(sf::Vector2f(spaceOcupedX, spaceOcupedY));
        return Texture::getInstace()->getSpikeTrap();
        break;
    
    default:
        break;
    }
} 