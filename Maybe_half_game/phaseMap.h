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

    sf::Sprite phase1Sprite;
    sf::Sprite phase2Sprite;

public:
    PhaseMap();
    ~PhaseMap();

    // false = error
    bool loadMapTileProprieties();
    bool draw(sf::RenderWindow& window);
};