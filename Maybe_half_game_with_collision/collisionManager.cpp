#include "collisionManager.h"

#include "phaseManager.h"

CollisionManager* CollisionManager::c_instance = nullptr;

CollisionManager::CollisionManager()
{
    player1 = Player::getInstance()->getPlayer1();
    phaseMap = PhaseManager::getInstance()->getPhaseMap();
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

    for (i = player1->getPosition().y / 32; i < ((player1->getPosition().y / 32) + 1); i++)
        for (j = player1->getPosition().x / 32; j < ((player1->getPosition().x / 32) + 1); j++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X" << std::endl;
                    player1->collideX(tile);
                }
            }
}

bool CollisionManager::objectCollideGroundY()
{
    int i, j;

    for (i = player1->getPosition().y / 32; i < ((player1->getPosition().y / 32) + 1); i++)
        for (j = player1->getPosition().x / 32; j < ((player1->getPosition().x / 32) + 1); j++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (player1->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em Y" << std::endl;
                    player1->collideY(tile);
                    return true;
                }
            }    
    return false;
}