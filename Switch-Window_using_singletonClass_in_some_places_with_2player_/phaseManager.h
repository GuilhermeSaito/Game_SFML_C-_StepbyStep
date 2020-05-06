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

    bool isPhase1;

public:
    static PhaseManager* getInstance();
    ~PhaseManager();

    int Start(sf::RenderWindow& window) override;

    int Phase1(sf::RenderWindow& window);
    int Phase2(sf::RenderWindow& window);

    void setIsPhase1(bool p);
};