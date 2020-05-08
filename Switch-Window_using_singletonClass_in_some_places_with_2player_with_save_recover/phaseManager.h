#pragma once

#include "switchWindow.h"

class PhaseManager: public SwitchWindow
{
private:
    PhaseManager();
    PhaseManager(const PhaseManager&);
    static PhaseManager* p_instance;
    
    sf::Event event;
    sf::Sprite spritePhase1;
    sf::Sprite spritePhase2;
    sf::Text menu1;
    sf::Text menu2;
    sf::Text menu3;

    bool isPhase1;
    int phaseSatate;

public:
    static PhaseManager* getInstance();
    ~PhaseManager();

    int Start(sf::RenderWindow& window) override;

    int Phase1(sf::RenderWindow& window);
    int Phase2(sf::RenderWindow& window);

    int escPressed(sf::RenderWindow& window);

    void setIsPhase1(bool p);
    bool getIsPhase1();
};