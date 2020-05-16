#include "collisionManager.h"

#include "phaseManager.h"

CollisionManager* CollisionManager::c_instance = nullptr;

CollisionManager::CollisionManager()
{
    player1 = Player::getInstance()->getPlayer1();
    phaseMap = PhaseManager::getInstance()->getPhaseMap();
    enemies1 = PhaseManager::getInstance()->getEnemy1();
    enemies2 = PhaseManager::getInstance()->getEnemy2();
    boss = PhaseManager::getInstance()->getBoss();
}

CollisionManager::~CollisionManager()
{
    delete c_instance;
}

CollisionManager* CollisionManager::getInstance()
{
    if (!c_instance)
        c_instance = new CollisionManager;
    return c_instance;
}

void CollisionManager::objectCollideGroundX()
{
    int i, j;

    for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y / 32) + 1); j++)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X" << std::endl;
                    player1->collideX(tile);
                }
            }

    /*for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y / 32) + 1); j++)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X" << std::endl;
                    player1->collideX(tile);
                }
            }

    for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y / 32) + 1); j++)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X" << std::endl;
                    player1->collideX(tile);
                }
            }*/

    for (j = boss->getPosition().y / 32; j < ((boss->getPosition().y / 32) + 1); j++)
        for (i = boss->getPosition().x / 32; i < ((boss->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (boss->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X - BOss" << std::endl;
                    boss->collideX(tile);
                }
            }
}

void CollisionManager::objectCollideGroundY()
{
    int i, j;

    for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y / 32) + 1); j++)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em Y" << std::endl;
                    player1->collideY(tile);
                }
            } 

    /*for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y / 32) + 1); j++)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em Y" << std::endl;
                    player1->collideY(tile);
                }
            } 

    for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y / 32) + 1); j++)
        for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x / 32) + 1); i++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em Y" << std::endl;
                    player1->collideY(tile);
                }
            }*/ 

    cout << "Vai entrar no for" << endl;
    for (j = boss->getPosition().y / 32; j < ((boss->getPosition().y / 32) + 1); j++)
        for (i = boss->getPosition().x / 32; i < ((boss->getPosition().x / 32) + 1); i++)
        {
            cout << "Entro no for" << endl;
            if (phaseMap->isValidTile(i, j))
            {
                cout << "Eh um tile valido" << endl;
                Tile* tile = phaseMap->getTile(i, j);
                if (boss->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em Y - Boss" << std::endl;
                    boss->collideY(tile);
                }
            }  
        }
}