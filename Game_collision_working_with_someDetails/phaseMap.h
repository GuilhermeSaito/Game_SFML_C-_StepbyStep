#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "tile.h"

class PhaseMap
{
private:
    std::vector<std::vector<Tile*>> tileMap;
    int alturaMax;
    int larguraMax;

    sf::Sprite phase1Sprite1;
    sf::Sprite phase1Sprite2;
    sf::Sprite phase1Sprite3;
    sf::Sprite phase1Sprite4;
    sf::Sprite phase1Sprite5;
    sf::Sprite phase2Sprite1;
    sf::Sprite phase2Sprite2;
    sf::Sprite phase2Sprite3;
    sf::Sprite phase2Sprite4;
    sf::Sprite phase2Sprite5;

public:
    PhaseMap();
    ~PhaseMap();

    // false = error
    bool loadMapTileProprieties();
    bool draw(sf::RenderWindow& window);

    std::vector<std::vector<Tile*>> getMatrixTile();
    Tile* getTile(int posX, int posY);
    bool isValidTile(int i, int j);
};