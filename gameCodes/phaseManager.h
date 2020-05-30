#pragma once

#include "switchWindow.h"
#include "enemy1.h"
#include "enemy2.h"
#include "boss.h"
#include "phaseMap.h"
#include "player.h"

class PhaseManager: public SwitchWindow
{
private:
    PhaseManager();
    PhaseManager(const PhaseManager&);
    static PhaseManager* p_instance;

    sf::Event event;
    sf::Text menu1;
    sf::Text menu2;
    sf::Text menu3;

    bool isPhase1;
    int phaseSatate;
    int gameState;
    std::string pathToLoadPhase;

    //Enemies
    float timer = 0.f;
    float damageTimer = 0.f; //to regulate how many times the blayer can be injured
    float damageDealerTimer = 0.f;//to regulate how many times the player can deal damage (boss only)
    float maxTimer = 60.f;
    std::vector<Enemy1*> enemies1;
    std::vector<Enemy2*> enemies2;
    Boss boss;
    int enemyQuantity = 0;

    PhaseMap phaseMap;
    Player1* player1;

public:
    static PhaseManager* getInstance();
    ~PhaseManager();

    int Start(sf::RenderWindow& window) override;

    int Phase1(sf::RenderWindow& window);
    int Phase2(sf::RenderWindow& window);

    void escPressed(sf::RenderWindow& window);

    //Updates
    void updatePollEvents(sf::RenderWindow& window);
    void updateEnemies1();
    void updateEnemies2();
    void update(sf::RenderWindow& window);

    void render(sf::RenderWindow& window);

    void setIsPhase1(bool p);
    bool getIsPhase1();

    std::string getPathLoadPhase();

    PhaseMap* getPhaseMap();
    std::vector<Enemy1*> getEnemy1();
    std::vector<Enemy2*> getEnemy2();
    Boss* getBoss();
};
