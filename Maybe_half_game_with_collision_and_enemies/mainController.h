#pragma once

#include "switchWindow.h"
#include "splashScreen.h"
#include "openMenu.h"
#include "phaseManager.h"

using std::vector;


class MainController
{
private:
    sf::RenderWindow window;
    vector<SwitchWindow*> switcher;

    SplashScreen splashScreen;
    OpenMenu openMenu;

public:
    MainController();
    ~MainController();

    void Initialize();
};