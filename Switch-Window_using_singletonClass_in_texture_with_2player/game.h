#pragma once

#include "switchWindow.h"

class Game: public SwitchWindow
{
private:
    // Delete this
    sf::Sprite backGroundSprite;
public:
    Game();
    ~Game();

    int Start(sf::RenderWindow& window) override;

    void setWindow(sf::RenderWindow* window);
    sf::RenderWindow getWindow();
};