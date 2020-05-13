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

class CollisionManager
{
private:
    CollisionManager();
    CollisionManager(CollisionManager const&);
    static CollisionManager* c_instance;

    Player1* player1;
    PhaseMap* phaseMap;

public:
    ~CollisionManager();
    static CollisionManager* getInstance();

    void objectCollideGroundX();
    bool objectCollideGroundY();
};