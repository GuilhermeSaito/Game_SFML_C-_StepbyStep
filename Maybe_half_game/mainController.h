#pragma once

#include "switchWindow.h"
#include "splashScreen.h"
#include "openMenu.h"
#include "phaseManager.h"

using std::vector;


class MainController
{
private:
    MainController();
    MainController(MainController const&);
    static MainController* instance;

    sf::RenderWindow window;
    vector<SwitchWindow*> switcher;

    SplashScreen splashScreen;
    OpenMenu openMenu;

public:
    static MainController* getInstance();
    ~MainController();

    void Initialize();

    sf::RenderWindow& getMainWindow();
};