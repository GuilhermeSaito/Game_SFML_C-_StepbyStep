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
#include "phaseManager.h"

class CollisionManager
{
private:
    CollisionManager();
    CollisionManager(CollisionManager const&);
    static CollisionManager* c_instance;

    Player1* player1;
    PhaseMap* phaseMap;
    std::vector<Enemy1*> enemies1;
    std::vector<Enemy2*> enemies2;
    Boss* boss;

    // Time to not take damage constantly
    sf::Clock kurokiEnemy1;
    sf::Clock kurokiEnemy2;
    sf::Clock kurokiBoss;

public:
    ~CollisionManager();
    static CollisionManager* getInstance();

    void addEnemy1(Enemy1* e1);
    void addEnemy2(Enemy2* e2); 

    void removeEnemy1(Enemy1* r1);
    void removeEnemy2(Enemy2* r2);

    void collisionManager();

    void player1Collision();
    void player2Collision();
    void enemy1Collision();
    void enemy2Collision();
    void bossCollision();
};