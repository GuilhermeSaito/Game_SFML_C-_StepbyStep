#include "tile.h"

// Esse spaceOcuped = Local em que É DESENHADO NO SFML, ou seja, o X e Y SÃO DIFERENTES
Tile::Tile(int numTle, int spaceOcupedX, int spaceOcupedY):
    numProprietieTile{numTle},
    spaceOcuped{sf::Vector2f(spaceOcupedX, spaceOcupedY)}
{
    if (numTle != 0)
    {
        tileSprite.setTexture(*(TileManager::getInstance()->getTileTexture(numTle, rectTile, spaceOcupedX, spaceOcupedY)));
        tileSprite.setPosition(rectTile.getPosition());
    }
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow& window)
{
    if (numProprietieTile != 0)
        window.draw(tileSprite);
}

sf::FloatRect Tile::getBoundBox()
{
    return sf::FloatRect(spaceOcuped.x, spaceOcuped.y, rectTile.getSize().x, rectTile.getSize().y);
}

sf::Vector2f Tile::getPosition()
{
    return spaceOcuped;
}