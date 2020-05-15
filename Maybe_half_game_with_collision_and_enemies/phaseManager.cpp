#include "phaseManager.h"
#include "collisionManager.h"

#include "player.h"
#include "save.h"

PhaseManager* PhaseManager::p_instance = NULL;

PhaseManager::PhaseManager()
{
	srand(time(NULL));

	menu1.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	menu2.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	menu3.setFont(*(Texture::getInstace()->getOpenMenuFont()));

	player1 = Player::getInstance()->getPlayer1();
}

PhaseManager::~PhaseManager()
{
	delete p_instance;
	for (Enemy1* e : enemies1)
		delete e;

	for (Enemy2* e : enemies2)
		delete e;

	delete boss;
}

PhaseManager* PhaseManager::getInstance()
{
    if (!p_instance)
        p_instance = new PhaseManager;
    return p_instance;
}


int PhaseManager::Start(sf::RenderWindow& window)
{
	flag = true;
    if (isPhase1)
	{
		pathToLoadPhase = "gameMap1.json";
		phaseMap.loadMapTileProprieties();
        return (Phase1(window));
	}
    else
	{
		pathToLoadPhase = "gameMap2.json";
		phaseMap.loadMapTileProprieties();
        return (Phase2(window));
	}
}

int PhaseManager::Phase1(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 1" << endl;
	gameState = 0;
    while (window.isOpen())
    {
        this->update(window, 1);
		if (gameState == -1)
			return -1;
		else if (gameState == 2)
			return 1;
		this->render(1, window);
    }

		for (Enemy1* e : enemies1)
			delete e;

		for (Enemy2* e : enemies2)
			delete e;

		this->enemyQuantity = 0;
}

int PhaseManager::Phase2(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 2" << endl;
	gameState = 0;
    while (window.isOpen())
    {
       this->update(window, 2);
		if (gameState == -1)
			return -1;
		else if (gameState == 2)
			return 1;
	   this->render(2, window);
    }

		for (Enemy1* e : enemies1)
			delete e;

		for (Enemy2* e : enemies2)
			delete e;

		delete boss;

		this->enemyQuantity = 0;
}

/*
	return:
		1 - Continue - Dont do nothing
		2 - Save - Save the progress and go back to mainMenu(openMenu.cpp/.h)
		3 - Exit - Close the game without saving
		-1 - Exit - Game Closed
*/
void PhaseManager::escPressed(sf::RenderWindow& window)
{
	sf::Event Event;
	int menu = 1;

	menu1.setPosition(sf::Vector2f(460, 280));
	menu1.setString("Continue");
	menu1.setCharacterSize(25);

	menu2.setPosition(sf::Vector2f(460, 340));
	menu2.setString("Save");
	menu2.setCharacterSize(25);

	menu3.setPosition(sf::Vector2f(460, 400));
	menu3.setString("Exit");
	menu3.setCharacterSize(25);

while (true)
	{
		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
				gameState = -1;
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu--;
					break;
				case sf::Keyboard::Down:
					menu++;
					break;
                // Keyboard::Return = Enter
				case sf::Keyboard::Return:
					if (menu == 1)
					{
						gameState = 1;
						return;
					}
					else if (menu == 2)
					{
						gameState = 2;
						return;
					}
					else
					{
						gameState = -1;
						return;
					}
					break;
				default:
					break;
				}
				// Don't letting the menu go for a invalid number.
				if (menu < 1)
					menu = 1;
				if (menu > 3)
					menu = 3;
			}
		}

		if (menu == 1)
		{
			menu1.setFillColor(sf::Color(255, 0, 0, 255));
			menu2.setFillColor(sf::Color(255, 255, 255, 255));
			menu3.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 2)
		{
			menu1.setFillColor(sf::Color(255, 255, 255, 255));
			menu2.setFillColor(sf::Color(255, 0, 0, 255));
			menu3.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else
		{
			menu1.setFillColor(sf::Color(255, 255, 255, 255));
			menu2.setFillColor(sf::Color(255, 255, 255, 255));
			menu3.setFillColor(sf::Color(255, 0, 0, 255));
		}

		window.clear();

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}

void PhaseManager::updatePollEvents(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		// Window closed
		if (event.type == sf::Event::Closed)
			phaseSatate = -1;
			//Key pressed
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				// Se for precionado o ESCs
				case sf::Keyboard::Escape:
					escPressed(window);
					if (gameState == 2)
						Save::getInstance()->Save_save();
					break;
				}
			}
	}
}

void PhaseManager::updateEnemies1()
{
	float posxp = player1->getPosition().x;
	float posyp = player1->getPosition().y;

	if (this->enemyQuantity == 0)
	{
		if (posxp >=200)
		{
			this->enemies1.push_back(new Enemy1(760, 400, 30));
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 1)
	{
		if (posxp >=1200)
		{
			this->enemies2.push_back(new Enemy2(1760, 550, 30));
			this->enemyQuantity++;
		}
	}

	for (auto *enemy1 : this->enemies1)
	{
		enemy1->update(posxp);
	}

	for (auto*enemy2 : this->enemies2)
	{
		enemy2->update(posxp);
	}

	if (this->timer == this->maxTimer)
	{
		for (auto*enemy2 : this->enemies2)
			enemy2->projectileMaker(posxp, posyp);

		this->timer=0.f;
	}
}

void PhaseManager::updateEnemies2()
{
	float posxp = player1->getPosition().x;
	float posyp = player1->getPosition().y;

	if (this->enemyQuantity == 0)
	{
		if (posxp >=100)
		{
			this->enemies1.push_back(new Enemy1(300, 500, 30));
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 1)
	{
		if (posxp >= 1500)
		{
			this->enemies2.push_back(new Enemy2(2060, 550, 30));
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 2)
	{
		if (posxp >= 2000)
		{
			this->boss = new Boss(4400, 400, 100);
			this->enemyQuantity++;
		}
	}

	for (auto *enemy1 : this->enemies1)
	{
		enemy1->update(posxp);
	}

	for (auto*enemy2 : this->enemies2)
	{
		enemy2->update(posxp);
	}

	this->boss->update(posxp);

	if (this->timer == this->maxTimer)
	{
		for (auto*enemy2 : this->enemies2)
			enemy2->projectileMaker(posxp, posyp);

			boss->projectileMaker(posxp, posyp);

		this->timer=0.f;
	}
}

void PhaseManager::update(sf::RenderWindow& window, int i)
{
	if (i==1)
		this->updateEnemies1();
	else
		this->updateEnemies2();

	this->timer += 0.5;

	CollisionManager::getInstance()->objectCollideGroundX(boss, &enemies1, &enemies2);
	CollisionManager::getInstance()->objectCollideGroundY(boss, &enemies1, &enemies2);

	this->updatePollEvents(window);
}

void PhaseManager::render(int i, sf::RenderWindow& window)
{
	window.clear();

	phaseMap.draw(window);


	for (auto *enemy1 : this->enemies1)
	{
		enemy1->render(&window);
	}

	for (auto *enemy2 : this->enemies2)
	{
		enemy2->render(&window);
	}

	this->boss->render(&window);

	Player::getInstance()->draw(window);
	window.display();
}

void PhaseManager::setIsPhase1(bool p)
{
    isPhase1 = p;
}

bool PhaseManager::getIsPhase1()
{
	return isPhase1;
}

std::string PhaseManager::getPathLoadPhase()
{
	return pathToLoadPhase;
}

PhaseMap* PhaseManager::getPhaseMap()
{
	return &phaseMap;
}
