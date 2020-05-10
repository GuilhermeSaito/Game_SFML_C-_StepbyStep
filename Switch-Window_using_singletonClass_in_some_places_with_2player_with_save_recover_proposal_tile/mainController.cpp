#include "mainController.h"

MainController::MainController(int argc, char** argv)
{
    Initialize();
}

MainController::~MainController()
{
}

void MainController::Initialize()
{
	int screen = 0;

	//Window creation			width, hight
    window.create(sf::VideoMode(1120, 672), "Us's Game");
	window.setFramerateLimit(60);
    cout << "[*] Generating window..." << endl;

	//Mouse cursor no more visible
	window.setMouseCursorVisible(false);

	//Screens preparations, first to show will be the splashScreen
	switcher.push_back(&splashScreen);
    switcher.push_back(&openMenu);
    switcher.push_back(PhaseManager::getInstance());

	//Main loop
	while (screen >= 0)
	{
		screen = switcher[screen]->Start(window);
	}

    EXIT_SUCCESS;
}