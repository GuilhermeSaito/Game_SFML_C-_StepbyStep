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

void CollisionManager::objectCollideGroundX(Boss *boss, std::vector<Enemy1*> *enemies1, std::vector<Enemy2*> *enemies2)
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

    for (auto* enemy1 : this->enemies1)
    {
      for (i = enemy1->getPosition().y / 32; i < ((enemy1->getPosition().y / 32) + 1); i++)
          for (j = enemy1->getPosition().x / 32; j < ((enemy1->getPosition().x / 32) + 1); j++)
              if (phaseMap->isValidTile(i, j))
              {
                  Tile* tile = phaseMap->getTile(i, j);
                  if (enemy1->getBoundBox().intersects(tile->getBoundBox()))
                  {
                      std::cout << "Ocorreu a colisão em X" << std::endl;
                      enemy1->collideX(tile);
                  }
              }
    }

    for (auto* enemy2 : this->enemies2)
    {
      for (i = enemy2->getPosition().y / 32; i < ((enemy2->getPosition().y / 32) + 1); i++)
          for (j = enemy2->getPosition().x / 32; j < ((enemy2->getPosition().x / 32) + 1); j++)
              if (phaseMap->isValidTile(i, j))
              {
                  Tile* tile = phaseMap->getTile(i, j);
                  if (enemy2->getBoundBox().intersects(tile->getBoundBox()))
                  {
                      std::cout << "Ocorreu a colisão em X" << std::endl;
                      enemy2->collideX(tile);
                  }
              }
    }

    for (i = boss->getPosition().y / 32; i < ((boss->getPosition().y / 32) + 1); i++)
        for (j = boss->getPosition().x / 32; j < ((boss->getPosition().x / 32) + 1); j++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (boss->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X" << std::endl;
                    boss->collideX(tile);
                }
            }
}

void CollisionManager::objectCollideGroundY(Boss *boss, std::vector<Enemy1*> *enemies1, std::vector<Enemy2*> *enemies2)
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
                }
            }

    for (auto* enemy1 : this->enemies1)
    {
      for (i = enemy1->getPosition().y / 32; i < ((enemy1->getPosition().y / 32) + 1); i++)
          for (j = enemy1->getPosition().x / 32; j < ((enemy1->getPosition().x / 32) + 1); j++)
              if (phaseMap->isValidTile(i, j))
              {
                  Tile* tile = phaseMap->getTile(i, j);
                  if (enemy1->getBoundBox().intersects(tile->getBoundBox()))
                  {
                      std::cout << "Ocorreu a colisão em X" << std::endl;
                      enemy1->collideY(tile);
                  }
              }
    }

    for (auto* enemy2 : this->enemies2)
    {
      for (i = enemy2->getPosition().y / 32; i < ((enemy2->getPosition().y / 32) + 1); i++)
          for (j = enemy2->getPosition().x / 32; j < ((enemy2->getPosition().x / 32) + 1); j++)
              if (phaseMap->isValidTile(i, j))
              {
                  Tile* tile = phaseMap->getTile(i, j);
                  if (enemy2->getBoundBox().intersects(tile->getBoundBox()))
                  {
                      std::cout << "Ocorreu a colisão em X" << std::endl;
                      enemy2->collideY(tile);
                  }
              }
    }

    for (i = boss->getPosition().y / 32; i < ((boss->getPosition().y / 32) + 1); i++)
        for (j = boss->getPosition().x / 32; j < ((boss->getPosition().x / 32) + 1); j++)
            if (phaseMap->isValidTile(i, j))
            {
                Tile* tile = phaseMap->getTile(i, j);
                if (boss->getBoundBox().intersects(tile->getBoundBox()))
                {
                    std::cout << "Ocorreu a colisão em X" << std::endl;
                    boss->collideY(tile);
                }
            }
}
