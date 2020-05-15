#pragma once

// Verificando todas as colisões possíveis no jogo:
/*
    Player with:
        Floor (plataforma, trap, pedra q cai)
        Inimigo
        Projétil

    Inimigo with:
        Chão (...)
        Player(s)

    Projétil with:
        Chão (...) <---- Caso bata, ele deve sumir
        Player(s)  <---- Da dano e deve sumir se intersecta
*/
#include "phaseMap.h"
#include "player.h"
#include "enemy1.h"
#include "enemy2.h"
#include "boss.h"

class CollisionManager
{
private:
    CollisionManager();
    CollisionManager(CollisionManager const&);
    static CollisionManager* c_instance;

    Player1* player1;
    PhaseMap* phaseMap;

    //enemies
    std::vector<Enemy1*> enemies1;
    std::vector<Enemy2*> enemies2;
    Boss* boss;

public:
    ~CollisionManager();
    static CollisionManager* getInstance();

    void objectCollideGroundX(Boss *boss, std::vector<Enemy1*> *enemies1, std::vector<Enemy2*> *enemies2);
    void objectCollideGroundY(Boss *boss, std::vector<Enemy1*> *enemies1, std::vector<Enemy2*> *enemies2);
};
