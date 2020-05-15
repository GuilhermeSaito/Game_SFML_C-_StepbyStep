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
    //larguraMax *= -1;
    int contI = 0;
    int posX = 0;
    int posY = 0;

    // Carregando as propriedades de cada tile da fase.
    // Indo da esquerda para a direita, depois de baixo para cima
    // Mas vou tirar todos os lugares q tem 0 = N tem nada
    for (int i = 0; i < alturaMax; i++)
    {
        std::vector<Tile*> tileLinha;
        for (int j = 0; j < larguraMax; j++)
        {
            int tilePropriedade = jMap["layers"][0]["data"][i*larguraMax + j];
            if (tilePropriedade == 5)
                tileLinha.push_back(new Tile(tilePropriedade, j*64, i*64));
            else if (tilePropriedade != 0)
                tileLinha.push_back(new Tile(tilePropriedade, j*32, i*32));
        }
        //contI++;
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
    /*
    for (int i = 0; i < alturaMax; i++)
        for (int j = 0; j < larguraMax; j++)
            tileMap[i][j]->draw(window);
    */
}