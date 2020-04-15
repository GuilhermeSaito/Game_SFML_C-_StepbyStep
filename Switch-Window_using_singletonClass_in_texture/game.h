#pragma once

#include "switchWindow.h"
#include "player.h"

class Game: public SwitchWindow
{
private:
    Player player1;

public:
    Game();
    ~Game();

    int Start(sf::RenderWindow& window) override;

    void setWindow(sf::RenderWindow* window);
    sf::RenderWindow getWindow();
};