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

    for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x + player1->getSize().x) / 32); i++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(i, player1->getPosition().y/32))
            continue;
        Tile* tile = phaseMap->getTile(i, (player1->getPosition().y/32));
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
        {
            if (tile->getNumTile() == 5)
              player1->hp == 0;

            cout << "PosPlayerX: " << i << endl << "PosTileX: " << tile->getPosition().x/32 << endl;
            player1->collideX(tile);
        }
    }

    for (auto *enemy1 : enemies1)
    {
      for (i = enemy1->getPosition().x / 32; i < ((enemy1->getPosition().x + enemy1->getSize().x) / 32); i++)
      {
          if (!phaseMap->isValidTile(i, enemy1->getPosition().y/32))
              continue;

          Tile* tile = phaseMap->getTile(i, enemy1->getPosition().y/32);
          if (enemy1->getBoundBox().intersects(tile->getBoundBox()))
          {
              enemy1->collideX(tile);
              enemy1->jump();
          }

      }
    }

    for (auto *enemy2 : enemies2)
    {
      for (i = enemy2->getPosition().x / 32; i < ((enemy2->getPosition().x + enemy2->getSize().x) / 32); i++)
      {
          if (!phaseMap->isValidTile(i, enemy2->getPosition().y/32))
              continue;

          Tile* tile = phaseMap->getTile(i, enemy2->getPosition().y/32);
          if (enemy2->getBoundBox().intersects(tile->getBoundBox()))
          {
              enemy2->collideX(tile);
              enemy2->jump();
          }

      }
    }

    for (i = boss->getPosition().x / 32; i < ((boss->getPosition().x + boss->getSize().x) / 32); i++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(i, boss->getPosition().y / 32))
            continue;
        Tile* tile = phaseMap->getTile(i, (boss->getPosition().y/32));
        if (boss->getBoundBox().intersects(tile->getBoundBox()))
        {
            cout << "PosPlayerX: " << i << endl << "PosTileX: " << tile->getPosition().x/32 << endl;
            boss->collideX(tile);
            boss->jump();
        }
    }
}

/*
    Tenho que dividir por 32 por causa do "quadriculado" do mapa. (quando se divide por 32, o número sempre será < 32)

*/

void CollisionManager::objectCollideGroundY()
{
    int i, j;

    for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y + player1->getSize().y) / 32); j++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(player1->getPosition().x / 32, j))
        {
          continue;
        }

        Tile* tile = phaseMap->getTile(player1->getPosition().x / 32, j);
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
        {
            if (tile->getNumTile() == 5)
              player1->hp == 0;
            
            std::cout << player1->getPosition().x/32 <<", " << player1->getPosition().y/32 << std::endl;
            player1->collideY(tile);
        }
        else
          player1->onGround = false;
    }

    for (auto *enemy1 : enemies1)
    {
      for (j = enemy1->getPosition().y / 32; j < ((enemy1->getPosition().y + enemy1->getSize().y) / 32); j++)
      {
          if (!phaseMap->isValidTile(enemy1->getPosition().x/32, j))
          {
              continue;
          }

          Tile* tile = phaseMap->getTile(enemy1->getPosition().x/32, j);
          if (enemy1->getBoundBox().intersects(tile->getBoundBox()))
          {
              std::cout << "Ocorreu a colisão em Y - enemy1" << std::endl;
              enemy1->collideY(tile);
          }
          else
            enemy1->onGround = false;

      }
    }

    for (auto *enemy2 : enemies2)
    {
      for (j = enemy2->getPosition().y / 32; j < ((enemy2->getPosition().y + enemy2->getSize().y) / 32); j++)
      {
          if (!phaseMap->isValidTile(enemy2->getPosition().x/32, j))
          {
              continue;
          }

          Tile* tile = phaseMap->getTile(enemy2->getPosition().x/32, j);
          if (enemy2->getBoundBox().intersects(tile->getBoundBox()))
          {
              std::cout << "Ocorreu a colisão em Y - enemy2" << std::endl;
              enemy2->collideY(tile);
          }
          else
            enemy2->onGround = false;

      }
    }

    for (j = boss->getPosition().y / 32; j < ((boss->getPosition().y + boss->getSize().y) / 32); j++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(boss->getPosition().x / 32, j))
        {
            continue;
        }

        Tile* tile = phaseMap->getTile(boss->getPosition().x / 32, j);
        if (boss->getBoundBox().intersects(tile->getBoundBox()))
        {
            boss->collideY(tile);
        }
        else
          boss->onGround = false;

    }
}

void CollisionManager::updateEnemiesCollision()
{
  enemies1 = PhaseManager::getInstance()->getEnemy1();
  enemies2 = PhaseManager::getInstance()->getEnemy2();
}
