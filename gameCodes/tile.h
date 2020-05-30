#pragma once

#include "tileManager.h"

class Tile
{
private:
    int numProprietieTile;

    sf::RectangleShape rectTile;
    sf::Sprite tileSprite;
    // Como esse spaceOcuped é o local ond está localizado no desenho do SFML, para achar no veto
    // Simplesmente divide por 32;
    sf::Vector2f spaceOcuped;


public:
    Tile(int numTile, int spaceOcupedX, int spaceOcupedY);
    ~Tile();

    void draw(sf::RenderWindow& window);

    sf::FloatRect getBoundBox();

    sf::Vector2f getPosition();

    int getNumTile();
};
