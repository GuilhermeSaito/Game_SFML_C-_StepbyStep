#pragma once

#include <SFML/Graphics.hpp>
// Aqui que vai ser carregado a textura

class TileManager
{
private:
    TileManager();
    TileManager(TileManager const&);
    static TileManager* instance;

    enum TileType
    {
        BrickFloor = 1,
        IceFloor = 2,
        IceFloor2 = 3,
        PurpleFloor = 4,
        Spike = 5
    };

public:
    static TileManager* getInstance();
    ~TileManager();

    sf::Texture* getTileTexture(int tileType, sf::RectangleShape& rect, int spaceOcupedX, int spaceOcupedY);
};