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

sf::Texture* TileManager::getTileTexture(int tileType)
{
    switch (tileType)
    {
    case BrickFloor:
        return Texture::getInstace()->getBrickFloor();
        break;
    case IceFloor:
        return Texture::getInstace()->getIceFloor();
        break;
    case IceFloor2:
        return Texture::getInstace()->getIceFloor2();
        break;
    case PurpleFloor:
        return Texture::getInstace()->getPurpleFloor();
        break;
    case Spike:
        return Texture::getInstace()->getSpikeTrap();
        break;
    
    default:
        break;
    }
} 