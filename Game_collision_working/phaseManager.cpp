// Esse é o q a gente vai alter

#include "phaseManager.h"

#include "save.h"

#include "phaseMap.h"
#include "collisionManager.h"

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
}

PhaseManager* PhaseManager::getInstance()
{
    if (!p_instance)
        p_instance = new PhaseManager;
    return p_instance;
}

int PhaseManager::Start(sf::RenderWindow& window)
{
	// Apagar
	gameState = 0;
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
        this->update(window);
		if (gameState == -1)
			return -1;
		else if (gameState == 2)
			return 1;
		this->render(1, window);
    }
}

int PhaseManager::Phase2(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 2" << endl;
	gameState = 0;
    while (window.isOpen())
    {
       this->update(window);
		if (gameState == -1)
			return -1;
		else if (gameState == 2)
			return 1;
	   this->render(2, window);
    }
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
	// Arrumando o view.		Center: 560, 336	  Size:  1120, 672
	sf::View normalView(sf::Vector2f(560, 336), sf::Vector2f(1120, 672));
	window.setView(normalView);

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
			Enemy1* e1 = new Enemy1(10*32, 16*32, 30);
			this->enemies1.push_back(e1);
			CollisionManager::getInstance()->addEnemy1(e1);
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 1)
	{
		if (posxp >=1200)
		{
			Enemy2* e2 = new Enemy2(1760, 550, 30);
			this->enemies2.push_back(e2);
			CollisionManager::getInstance()->addEnemy2(e2);
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

	if (this->timer >= this->maxTimer)
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
			Enemy1* e1 = new Enemy1(10*32, 16*32, 30);
			this->enemies1.push_back(e1);
			CollisionManager::getInstance()->addEnemy1(e1);
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 1)
	{
		if (posxp >= 1500)
		{
			Enemy2* e2 = new Enemy2(1760, 550, 30);
			this->enemies2.push_back(e2);
			CollisionManager::getInstance()->addEnemy2(e2);
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

	boss.update(posxp);

	if (this->timer >= this->maxTimer)
	{
		for (auto*enemy2 : this->enemies2)
			enemy2->projectileMaker(posxp, posyp);

		boss.projectileMaker(posxp, posyp);

		this->timer=0.f;
	}
}

void PhaseManager::update(sf::RenderWindow& window)
{
	if (isPhase1)
		this->updateEnemies1();
	else
	{
		this->updateEnemies2();
	}

	this->timer += 0.5;

    CollisionManager::getInstance()->collisionManager();

	this->updatePollEvents(window);
}

void PhaseManager::render(int i, sf::RenderWindow& window)
{
	// Caso o player caia no "buraco", gameOver.
	if (player1->getPosition().y > 608)
	{
		gameState = 2;
		return;
	}
	// SE DER ALGUM ERRO NO INIMIGO, PROVAVELMENTE É AQUI.
	for (Enemy1* e : enemies1)
	{
		auto it = enemies1.begin();
		if (e->getPosition().y > 624)
		{
			enemies1.erase(it);
			CollisionManager::getInstance()->removeEnemy1(*it);
		}
		it++;
	}
	// DA MESMA FORMA COM ESSE INIMIGO AQUI.
	for (Enemy2* e : enemies2)
	{
		auto it = enemies2.begin();
		if (e->getPosition().y > 624)
		{
			enemies2.erase(it);
			CollisionManager::getInstance()->removeEnemy2(*it);
		}
		it++;
	}	


	// Setando o View no player1
	//							Center: playerPosition						Size:  1120, 672
	sf::View player1View(sf::Vector2f(player1->getPosition().x, 335), sf::Vector2f(1120, 672));
	window.setView(player1View);

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

	if (!isPhase1)
		boss.render(&window);

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
	return& phaseMap;
}


// USA ESSES MÉTODOS DO INIMIGO SOMENTE DEPOIS QUE ELE FOI "CRIADO" COM O NEW, SE N VAI SER NULO.
std::vector<Enemy1*> PhaseManager::getEnemy1()
{
	return enemies1;
}

std::vector<Enemy2*> PhaseManager::getEnemy2()
{
	return enemies2;
}

Boss* PhaseManager::getBoss()
{
	return& boss;
}