#pragma once

#include "switchWindow.h"
#include "enemy.h"
#include "phaseMap.h"

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
    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy*> enemies;

    //private functions
    void iniEnemies();  

    // Tile Map
    PhaseMap phaseMap;
    bool flag;  

public:
    static PhaseManager* getInstance();
    ~PhaseManager();

    int Start(sf::RenderWindow& window) override;

    int Phase1(sf::RenderWindow& window);
    int Phase2(sf::RenderWindow& window);

    void escPressed(sf::RenderWindow& window);

    //Updates
    void updatePollEvents(sf::RenderWindow& window);
    void updateEnemies();
    void update(sf::RenderWindow& window);

    void render(int i, sf::RenderWindow& window);

    void setIsPhase1(bool p);
    bool getIsPhase1();

    std::string getPathLoadPhase();
};