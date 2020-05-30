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
		this->render(window);
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
	   this->render(window);
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
			this->enemies1.push_back(new Enemy1(12*32, 17*32, 30));
			CollisionManager::getInstance()->updateEnemiesCollision();
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 1)
	{
		if (posxp >= 1200)
		{
			this->enemies2.push_back(new Enemy2(70*32, 17*32, 30));
			CollisionManager::getInstance()->updateEnemiesCollision();
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 2)
	{
		if (posxp >= 90*32)
		{
			this->enemies2.push_back(new Enemy2(123*32, 18*32, 30));
			CollisionManager::getInstance()->updateEnemiesCollision();
			this->enemyQuantity++;
		}
	}

	//updates enemies1, checks if he fell in a hole and checks for damage. For some reason it's not working with enemies 1
	int i = 0;
	for (auto *enemy1 : this->enemies1)
	{
		//checking for fall
		if (enemy1->getPosition().y >= 32*19.0343 && enemy1->getPosition().x > 32*80.f && enemy1->getPosition().x < 32*100.f)
		{
			std::cout << "caiu en1 1" << std::endl;
			this->enemies1.erase(enemies1.begin()+i);
		}

		//damage on the player
		if ((posxp-(enemy1->getPosition().x) <= 70.f && posxp-(enemy1->getPosition().x) > 0.f)||
		((enemy1->getPosition().x)-posxp <= 32.f && (enemy1->getPosition().x)-posxp > 0.f) &&
		abs(posyp-(enemy1->getPosition().y)) <= 31.f)
		{
			if (this->damageTimer == 0)
			{
				player1->hp -= 10;
				this->damageTimer++;
			}
		}

		//damage delt by the player
		if (abs(posxp-(enemy1->getPosition().x)) <= 17.f && enemy1->getPosition().y-posyp <= 32.f && enemy1->getPosition().y-posyp > 20.f)
		{
				this->player1->onGround = true;
				this->player1->jump();
				this->player1->points = enemy1->points;
				this->enemies1.erase(enemies1.begin()+i);
		}

		enemy1->update(posxp);
		i++;
	}

	//updates enemies2, checks if he fell in a hole and checks for damage
	i = 0;
	for (auto*enemy2 : this->enemies2)
	{
		if (enemy2->getPosition().y >= 32*19.0343 && enemy2->getPosition().x > 32*80.f && enemy2->getPosition().x < 32*100.f)
		{
			std::cout << "caiu en2 1" << std::endl;
			this->enemies2.erase(enemies2.begin()+i);
		}

		//damage on the player
		if ((posxp-(enemy2->getPosition().x) <= 70.f && posxp-(enemy2->getPosition().x) > 0.f) ||
		((enemy2->getPosition().x)-posxp <= 32.f && (enemy2->getPosition().x)-posxp > 0.f) &&
		abs(posyp-(enemy2->getPosition().y)) <= 31.f)
		{
			if (this->damageTimer == 0)
			{
				player1->hp -= 10;
				this->damageTimer++;
			}
		}

		//damage delt by the player
		if (abs(posxp-(enemy2->getPosition().x)) <= 20.f && enemy2->getPosition().y-posyp <= 32.f && enemy2->getPosition().y-posyp > 20.f)
		{
				this->player1->onGround = true;
				this->player1->jump();
				this->player1->points = enemy2->points;
				this->enemies2.erase(enemies2.begin()+i);
		}

		enemy2->update(posxp, this->player1, &this->damageTimer);
		i++;
	}

	//creates projectiles according to a time variable
	if (this->timer >= this->maxTimer)
	{
		for (auto*enemy2 : this->enemies2)
			enemy2->projectileMaker(posxp, posyp);

		this->timer=0.f;
	}

	//checks if player fell in a hole and if so, puts the wasted screen
	if (posyp >= 32*19.0343 && posxp > 32*79.f && posxp < 32*100.f)
	{
			std::cout << "vapo1" << std::endl;
			gameState = -1;
	}

	//updating damageTimer
	if (this->damageTimer != 0.f)
	{
		this->damageTimer++;
		if (this->damageTimer == this->maxTimer)
			this->damageTimer = 0.f;
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
			this->enemies1.push_back(new Enemy1(300, 17*32, 30));
			CollisionManager::getInstance()->updateEnemiesCollision();
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 1)
	{
		if (posxp >= 5*32)
		{
			this->enemies2.push_back(new Enemy2(33*32, 11*32, 30));
			CollisionManager::getInstance()->updateEnemiesCollision();
			this->enemyQuantity++;
		}
	}

	else if (this->enemyQuantity == 2)
	{
		if (posxp >= 50*32)
		{
			this->enemies2.push_back(new Enemy2(90*32, 17*32, 30));
			CollisionManager::getInstance()->updateEnemiesCollision();
			this->enemyQuantity++;
		}
	}

	int i = 0;
	for (auto *enemy1 : this->enemies1)
	{
		if (enemy1->getPosition().y >= 32*18.0343 && enemy1->getPosition().x > 32*26.f && enemy1->getPosition().x < 32*60.f)
			this->enemies1.erase(enemies1.begin()+i);

		//damage on the player
		if ((posxp-(enemy1->getPosition().x) <= 70.f && posxp-(enemy1->getPosition().x) > 0.f)||
		((enemy1->getPosition().x)-posxp <= 32.f && (enemy1->getPosition().x)-posxp > 0.f) &&
		abs(posyp-(enemy1->getPosition().y)) <= 31.f)
		{
			if (this->damageTimer == 0)
			{
				player1->hp -= 10;
				this->damageTimer++;
			}
		}

		//damage delt by the player
		if (abs(posxp-(enemy1->getPosition().x)) <= 17.f && enemy1->getPosition().y-posyp <= 32.f && enemy1->getPosition().y-posyp > 20.f)
		{
				this->player1->onGround = true;
				this->player1->jump();
				this->player1->points = enemy1->points;
				this->enemies1.erase(enemies1.begin()+i);
		}

		enemy1->update(posxp);
		i++;
	}



	i = 0;
	for (auto*enemy2 : this->enemies2)
	{
		if (enemy2->getPosition().y >= 32*18.0343 && enemy2->getPosition().x > 32*26.f && enemy2->getPosition().x < 32*60.f)
			this->enemies2.erase(enemies2.begin()+i);

		//damage on the player
		if ((posxp-(enemy2->getPosition().x) <= 70.f && posxp-(enemy2->getPosition().x) > 0.f) ||
		((enemy2->getPosition().x)-posxp <= 32.f && (enemy2->getPosition().x)-posxp > 0.f) &&
		abs(posyp-(enemy2->getPosition().y)) <= 31.f)
		{
			if (this->damageTimer == 0)
			{
				player1->hp -= 10;
				this->damageTimer++;
			}
		}

		//damage delt by the player
		if (abs(posxp-(enemy2->getPosition().x)) <= 20.f && enemy2->getPosition().y-posyp <= 32.f && enemy2->getPosition().y-posyp > 20.f)
		{
				this->player1->onGround = true;
				this->player1->jump();
				this->player1->points = enemy2->points;
				this->enemies2.erase(enemies2.begin()+i);
		}

		enemy2->update(posxp, this->player1, &this->damageTimer);
		i++;
	}

	//updating boss
		//damage on the player
		if ((posxp-(boss.getPosition().x) <= 92.f && posxp-(boss.getPosition().x) > 0.f) ||
		((boss.getPosition().x)-posxp <= 32.f && (boss.getPosition().x)-posxp > 0.f) &&
		abs(posyp-(boss.getPosition().y)) <= 31.f)
		{
			if (this->damageTimer == 0)
			{
				player1->hp -= 10;
				this->damageTimer++;
			}
		}

		//damage delt by the player
		if (abs(posxp-(boss.getPosition().x)) <= 20.f && boss.getPosition().y-posyp <= 32.f && boss.getPosition().y-posyp > 20.f)
		{
			if (this->damageDealerTimer == 0)
			{
				boss.hp -= 30;
				this->damageDealerTimer++;
				this->player1->jump();
			}

		}
		boss.update(posxp, this->player1, &this->damageTimer);

	//updating projectiles
	if (this->timer >= this->maxTimer)
	{
		for (auto*enemy2 : this->enemies2)
			enemy2->projectileMaker(posxp, posyp);

		boss.projectileMaker(posxp, posyp);

		this->timer=0.f;
	}

	//player falling
	if (posyp >= 32*18.0343 && posxp > 32*26.f && posxp < 32*60.f)
	{
			std::cout << "vapo2" << std::endl;
			gameState = -1;
	}

	//updating damageTimer
	if (this->damageTimer != 0.f)
	{
		this->damageTimer++;
		if (this->damageTimer == this->maxTimer)
			this->damageTimer = 0.f;
	}

	//updating damageDealerTimer
	if (this->damageDealerTimer != 0.f)
	{
		this->damageDealerTimer++;
		if (this->damageDealerTimer == this->maxTimer)
			this->damageDealerTimer = 0.f;
	}
}

void PhaseManager::update(sf::RenderWindow& window)
{
    CollisionManager::getInstance()->objectCollideGroundX();
    CollisionManager::getInstance()->objectCollideGroundY();

	if (isPhase1)
		this->updateEnemies1();
	else
	{
		this->updateEnemies2();
	}

	this->timer += 0.5;

	this->updatePollEvents(window);
}

void PhaseManager::render(sf::RenderWindow& window)
{
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
