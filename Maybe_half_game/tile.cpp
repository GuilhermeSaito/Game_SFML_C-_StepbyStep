#include "tile.h"

Tile::Tile(int numTle, int posX, int posY):
    numProprietieTile{numTle}
{
    tileSprite.setTexture(*(TileManager::getInstance()->getTileTexture(numTle)));
    pos = sf::Vector2f(posX, posY);
    tileSprite.setPosition(pos);
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow& window)
{
    //if (numProprietieTile != 0)
        window.draw(tileSprite);
}