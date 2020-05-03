#pragma once

#include "switchWindow.h"
#include "splashScreen.h"
#include "openMenu.h"
#include "game.h"

using std::vector;


class MainController
{
private:
    sf::RenderWindow window;
    vector<SwitchWindow*> switcher;

    SplashScreen splashScreen;
    OpenMenu openMenu;
    Game game;

public:
    MainController(int argc, char** argv);
    ~MainController();

    void Initialize();
};