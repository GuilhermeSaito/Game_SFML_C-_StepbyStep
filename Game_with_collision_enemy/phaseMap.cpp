#include "phaseMap.h"
#include "phaseManager.h"
#include "texture.h"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

PhaseMap::PhaseMap()
{
    phase1Sprite.setTexture(*(Texture::getInstace()->getPhase1Texture()));
    phase2Sprite.setTexture(*(Texture::getInstace()->getPhase2Texture()));
}

PhaseMap::~PhaseMap()
{
    for(std::vector<Tile*> v : tileMap) 
        for(Tile* t : v) 
            delete t;
}

bool PhaseMap::loadMapTileProprieties()
{
    std::string path = PhaseManager::getInstance()->getPathLoadPhase();
    std::ifstream in(path);
    if (!in.good())
    {
        std::cout << "Não foi possivel abrir o " << path << std::endl;
        return false;
    }
    std::cout << path << "\tLoaded" << std::endl;

    // Dar um jeito de limpar a tela e colocar novas propriedades nos tiles, caso haja mudança de fase

    json jMap;
    in >> jMap;

    alturaMax = jMap["height"];
    larguraMax = jMap["width"];

    // Carregando as propriedades de cada tile da fase e construindo a matriz de tile (o mapa).
    /*
        OBS:
        Como na construção da Matriz, por algum motivo a construção foi assim:
            - Como o mapa é um retângulo com a largura maior q a altura
            - ele faz um retângulo com a parte maior para baixo:
            ---     em vez de assim     --------    , por isso q o i e o j estão ao contrário
            - -                         -      -
            ---                         --------
    */
    for (int j = 0; j < alturaMax; j++)
    {
        std::vector<Tile*> tileLinha;
        for (int i = 0; i < larguraMax; i++)
        {
            int tilePropriedade = jMap["layers"][0]["data"][j*larguraMax + i];
            tileLinha.push_back(new Tile(tilePropriedade, i*32, j*32));
        }
        tileMap.push_back(tileLinha);
    }

    in.close();
}

bool PhaseMap::draw(sf::RenderWindow& window)
{
    bool isPhase1 = PhaseManager::getInstance()->getIsPhase1();
    if (isPhase1)
        window.draw(phase1Sprite);
    else
        window.draw(phase2Sprite);


    // Fazer desenhar em cada local, desenhando a fase inteira.
    for (std::vector<Tile*> i : tileMap)
        for (Tile* j : i)
            j->draw(window);
}

std::vector<std::vector<Tile*>> PhaseMap::getMatrixTile()
{
    return tileMap;
}

Tile* PhaseMap::getTile(int posX, int posY)
{
    // vai de 0 a 21 (altura)    e 0 a 175 (largura).
    return tileMap[posY][posX];
}

bool PhaseMap::isValidTile(int i, int j)
{
    if (((i >= 0) && (i <= larguraMax)) && ((j >= 0) && (j <= alturaMax)))
        return true;
    return false;
}