/*
  
    Tenho que dividir por 32 por causa do "quadriculado" do mapa. (quando se divide por 32, o número sempre será < 32)

*/

#include "collisionManager.h"

#include "phaseManager.h"

CollisionManager* CollisionManager::c_instance = nullptr;

CollisionManager::CollisionManager()
{
    player1 = Player::getInstance()->getPlayer1();
    phaseMap = PhaseManager::getInstance()->getPhaseMap();
    boss = PhaseManager::getInstance()->getBoss();
}

CollisionManager::~CollisionManager()
{
    delete c_instance;

    for (Enemy1* e1 : enemies1)
        delete e1;

    for (Enemy2* e2 : enemies2)
        delete e2;
}

CollisionManager* CollisionManager::getInstance()
{
    if (!c_instance)
        c_instance = new CollisionManager;
    return c_instance;
}

void CollisionManager::addEnemy1(Enemy1* e1)
{
    enemies1.push_back(e1);
}

void CollisionManager::addEnemy2(Enemy2* e2)
{
    enemies2.push_back(e2);
}

void CollisionManager::removeEnemy1(Enemy1* r1)
{
    for (auto it = enemies1.begin(); it < enemies1.end(); it++)
        if ((*it) == r1)
            enemies1.erase(it);
}

void CollisionManager::removeEnemy2(Enemy2* r2)
{
    for (auto it = enemies2.begin(); it < enemies2.end(); it++)
        if ((*it) == r2)
            enemies2.erase(it);
}

void CollisionManager::collisionManager()
{
    player1Collision();
    if (Player::getInstance()->getInstance())
        player2Collision();
    enemy1Collision();
    enemy2Collision();
    if (!PhaseManager::getInstance()->getIsPhase1())
        bossCollision();
}

void CollisionManager::player1Collision()
{
    int i, j;
    // Collision X with Tile 
    for (i = player1->getPosition().x / 32; i < ((player1->getPosition().x + player1->getSize().x) / 32); i++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(i, player1->getPosition().y / 32))
            continue;
        Tile* tile = phaseMap->getTile(i, (player1->getPosition().y/32));
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
            player1->collideX(tile);
    }

    // Collision Y with Tile
    for (j = player1->getPosition().y / 32; j < ((player1->getPosition().y + player1->getSize().y) / 32); j++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(player1->getPosition().x / 32, j))
            continue;
        Tile* tile = phaseMap->getTile(player1->getPosition().x / 32, j);
        if (player1->getBoundBox().intersects(tile->getBoundBox()))
            player1->collideY(tile);
    } 

    // Player attacking enemy when fall
    if (player1->getSpeed().y > 0)
    {
        for (Enemy1* e1 : enemies1)
            if (e1->getBoundBox().intersects(player1->getBoundBox()))
                e1->reciveDamage(player1->getAttackDamage());
        
        for (Enemy2* e2 : enemies2)
            if (e2->getBoundBox().intersects(player1->getBoundBox()))
                e2->reciveDamage(player1->getAttackDamage());

        if (boss->getBoundBox().intersects(player1->getBoundBox()))
            boss->reciveDamage(player1->getAttackDamage());
    }
}

void CollisionManager::player2Collision()
{
    // Ainda vou implementar
}

void CollisionManager::enemy1Collision()
{
    int i, j;
    // Collision X with Tile
    for (Enemy1* e1 : enemies1)
        for (i = e1->getPosition().x / 32; i < ((e1->getPosition().x + e1->getSize().x) / 32); i++)
        {
            // if is not a valit Tile, just dont process.
            if (!phaseMap->isValidTile(i, e1->getPosition().y / 32))
                continue;
            Tile* tile = phaseMap->getTile(i, (e1->getPosition().y/32));
            if (e1->getBoundBox().intersects(tile->getBoundBox()))
                e1->collideX(tile);
        }    

    // Collision Y with Tile
    for (Enemy1* e1 : enemies1)
        for (j = e1->getPosition().y / 32; j < ((e1->getPosition().y + e1->getSize().y) / 32); j++)
        {
            // if is not a valit Tile, just dont process.
            if (!phaseMap->isValidTile(e1->getPosition().x / 32, j))
                continue;
            Tile* tile = phaseMap->getTile(e1->getPosition().x / 32, j);
            if (e1->getBoundBox().intersects(tile->getBoundBox()))
                e1->collideY(tile);
        } 

    // Enemy dealing damage in Player
    sf::Time elapsed1 = kurokiEnemy1.getElapsedTime();
    if (elapsed1.asSeconds() >= 1)
    {
        kurokiEnemy1.restart();
        for (Enemy1* e1 : enemies1)
            if (e1->getBoundBox().intersects(player1->getBoundBox()))
                player1->takeDamage(e1->getAttackDamage());
    }
}

void CollisionManager::enemy2Collision()
{
    int i, j;
    // Collision X with Tile
    for (Enemy2* e2 : enemies2)
        for (i = e2->getPosition().x / 32; i < ((e2->getPosition().x + e2->getSize().x) / 32); i++)
        {
            // if is not a valit Tile, just dont process.
            if (!phaseMap->isValidTile(i, e2->getPosition().y / 32))
                continue;
            Tile* tile = phaseMap->getTile(i, (e2->getPosition().y/32));
            if (e2->getBoundBox().intersects(tile->getBoundBox()))
                e2->collideX(tile);
        } 

    // Collision Y with Tile
    for (Enemy2* e2 : enemies2)
        for (j = e2->getPosition().y / 32; j < ((e2->getPosition().y + e2->getSize().y) / 32); j++)
        {
            // if is not a valit Tile, just dont process.
            if (!phaseMap->isValidTile(e2->getPosition().x / 32, j))
                continue;
            Tile* tile = phaseMap->getTile(e2->getPosition().x / 32, j);
            if (e2->getBoundBox().intersects(tile->getBoundBox()))
                e2->collideY(tile);
        } 

    // Enemy dealing damage in Player
    sf::Time elapsed2 = kurokiEnemy2.getElapsedTime();
    if (elapsed2.asSeconds() >= 1)
    {
        kurokiEnemy2.restart();
        for (Enemy2* e2 : enemies2)
            if (e2->getBoundBox().intersects(player1->getBoundBox()))
                player1->takeDamage(e2->getAttackDamage());
    }
}

void CollisionManager::bossCollision()
{
    int i, j;
    // Collision X with Tile
    for (i = boss->getPosition().x / 32; i < ((boss->getPosition().x + boss->getSize().x) / 32); i++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(i, boss->getPosition().y / 32))
            continue;
        Tile* tile = phaseMap->getTile(i, (boss->getPosition().y/32));
        if (boss->getBoundBox().intersects(tile->getBoundBox()))
            boss->collideX(tile);
    }

    // COllision Y with Tile
    for (j = boss->getPosition().y / 32; j < ((boss->getPosition().y + boss->getSize().y) / 32); j++)
    {
        // if is not a valit Tile, just dont process.
        if (!phaseMap->isValidTile(boss->getPosition().x / 32, j))
            continue;
        Tile* tile = phaseMap->getTile(boss->getPosition().x / 32, j);
        if (boss->getBoundBox().intersects(tile->getBoundBox()))
            boss->collideY(tile);
    } 

    // Boss dealing damage in player
    sf::Time elapsed = kurokiBoss.getElapsedTime();
    if (elapsed.asSeconds() >= 1.5)
    {
        kurokiBoss.restart();
        if (boss->getBoundBox().intersects(player1->getBoundBox()))
            player1->takeDamage(boss->getAttackDamage());
    }
}
