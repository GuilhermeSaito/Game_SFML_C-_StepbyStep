#pragma once

#include "tileManager.h"

class Tile
{
private:
    int numProprietieTile;
    sf::RectangleShape tileShape;
    sf::Sprite tileSprite;
    sf::Vector2f pos;


public:
    Tile(int numTile, int posX, int posY);
    ~Tile();

    void draw(sf::RenderWindow& window);
};