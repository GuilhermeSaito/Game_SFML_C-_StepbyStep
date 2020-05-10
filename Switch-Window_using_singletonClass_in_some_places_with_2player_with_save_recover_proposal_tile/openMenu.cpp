#include "openMenu.h"

#include "player.h"
#include "phaseManager.h"
#include "save.h"

/*// SFGUI to use the Text Box Input
#include <>*/

OpenMenu::OpenMenu(void)
{
	Menu1.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu2.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu3.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu4.setFont(*(Texture::getInstace()->getOpenMenuFont()));

	Sprite.setTexture(*(Texture::getInstace()->getOpenMenuTexture()));
	Sprite.scale(sf::Vector2f(1.9, 2.6));
}

OpenMenu::~OpenMenu()
{
}

/************************************************************/

int OpenMenu::Start(sf::RenderWindow& window)
{
	//int alpha = 0;
	sf::Font Font;
	int menu = 1;
    

	Menu1.setString("New Game");
	Menu1.setPosition({ 580.f, 200.f });
	Menu1.setCharacterSize(25);

	Menu2.setString("Continue");
	Menu2.setPosition({ 580.f, 260.f });
	Menu2.setCharacterSize(25);

	Menu3.setString("Ranking");
	Menu3.setPosition({ 580.f, 320.f });
	Menu3.setCharacterSize(25);

	Menu4.setString("Exit");
	Menu4.setPosition({ 580.f, 380.f });
	Menu4.setCharacterSize(25);

	while (true)
	{
		//Verifying events
		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
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
				/*
					1 - New Game.
					2 - Continue
					3 - Ranking
					4 - Exit Program.
				*/
					if (menu == 1)
					{
						if (showCharacterSelection(window) == -1)
							return -1;
						return 2;
					}
					else if (menu == 2)
					{
						if (continueGame())
							return 2;
						return -1;
					}
					else if (menu == 3)
					{
						if (showNotImplementedYet(window))
							return (1);
						return -1;
					}
					else
					{
						return (-1);
					}
					break;
				default:
					break;
				}
				// Don't letting the menu go for a invalid number.
				if (menu < 1)
					menu = 1;
				if (menu > 4)
					menu = 4;
			}
		}

		//Sprite.setFillColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 1)
		{
			Menu1.setFillColor(sf::Color(255, 0, 0, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
			Menu4.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 2)
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 0, 0, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
			Menu4.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 3)
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 0, 0, 255));
			Menu4.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
			Menu4.setFillColor(sf::Color(255, 0, 0, 255));			
		}
		

		//Clearing screen
		window.clear();
		//Drawing
		window.draw(Sprite);
		window.draw(Menu1);
		window.draw(Menu2);
		window.draw(Menu3);
		window.draw(Menu4);

		window.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

/************************************************************/

int OpenMenu::showCharacterSelection(sf::RenderWindow& window)
{

	int menu = 1;

	Menu1.setString("1 Player  - 1 Phase");
	Menu1.setPosition({ 460.f, 220.f });
	Menu1.setCharacterSize(25);

	Menu2.setString("2 Players - 1 Phase");
	Menu2.setPosition({ 460.f, 280.f });
	Menu2.setCharacterSize(25);

	Menu3.setString("1 player  - 2 Phase");
	Menu3.setPosition({ 460.f, 340});
	Menu3.setCharacterSize(25);

	Menu4.setString("2 players - 2 Phase");
	Menu4.setPosition({ 460.f, 400});
	Menu4.setCharacterSize(25);


	while (true)
	{
		//Verifying events
	//int alpha_max;
	//int alpha_div;
	//bool playing;
		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
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
				/*
					1 - 1 Player	1 Phase
					2 - 2 Players	1 Phase
					3 - 1 Player	2 Phase
					4 - 2 Players	2 Phase
				*/
					if (menu == 1)
					{
						if (play1Player(window))
						{
							PhaseManager::getInstance()->setIsPhase1(true);
							return 2;
						}
						return -1;
					}
					else if (menu == 2)
					{
						if (play2Players(window))
						{
							PhaseManager::getInstance()->setIsPhase1(true);
							return 2;
						}
						return -1;
					}
					else if (menu == 3)
					{
						if (play1Player(window))
						{
							PhaseManager::getInstance()->setIsPhase1(false);
							return 2;
						}
						return -1;
					}
					else 						
					{
						if (play2Players(window))
						{
							PhaseManager::getInstance()->setIsPhase1(false);
							return 2;
						}
						return -1;
					}
					break;
				default:
					break;
				}
				// Don't letting the menu go for a invalid number.
				if (menu < 1)
					menu = 1;
				if (menu > 4)
					menu = 4;
			}
		}
		
		if (menu == 1)
		{
			Menu1.setFillColor(sf::Color(255, 0, 0, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
			Menu4.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 2)
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 0, 0, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
			Menu4.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else if (menu == 3)
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 0, 0, 255));
			Menu4.setFillColor(sf::Color(255, 255, 255, 255));
		}
		else
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
			Menu4.setFillColor(sf::Color(255, 0, 0, 255));
		}

		window.clear();
		
		window.draw(Menu1);
		window.draw(Menu2);
		window.draw(Menu3);
		window.draw(Menu4);

		window.display();
	}

	return -1;
}

/************************************************************/

// Input the name of the Player
bool OpenMenu::play1Player(sf::RenderWindow& window)
{
	int totalChar = 0;
	playerName1 = "";

	// Reutilizing the variable
	Menu1.setPosition(340.f, 360.f);
	Menu1.setFillColor(sf::Color(sf::Color::White));
	Menu1.setCharacterSize(40);
	Menu1.setString(playerName1);

	Menu2.setPosition(340.f, 100.f);
	Menu2.setFillColor(sf::Color(sf::Color::Red));
	Menu2.setCharacterSize(30);
	Menu2.setString("Type your character name: (Enter to Start) ");

	while (true)
	{
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::TextEntered)
			{
				// If backspace is pressed, erase the char
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (totalChar > 0))
					playerName1.erase(totalChar--, 1);
				// Allow any char of the ASCII table and limitating the name
				else if ((totalChar <= 14) && (totalChar >= 0))
				{
					playerName1 += (char)Event.text.unicode;
					totalChar++;
				}
				Menu1.setString(playerName1);
			}
			// close button clicked
			if (Event.type == sf::Event::Closed)
				return false;

			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				// Play button clicked
				case sf::Keyboard::Return:
					Player::getInstance()->setIsMultiplayer(false);
					Player::getInstance()->setPlayer1Name(playerName1);
					return true;

					break;
				
				default:
					break;
				}
			}
		}
		window.clear();

		window.draw(Menu1);
		window.draw(Menu2);
		
		window.display();
	}
}

/************************************************************/

// Input the name of the Players
bool OpenMenu::play2Players(sf::RenderWindow& window)
{
	int totalChar1 = 0;
	int totalChar2 = 0;
	int tabPressed = 1;
	playerName1 = "";
	playerName2 = "";

	// Reutilizing the variable
	Menu1.setPosition(340.f, 230.f);
	Menu1.setFillColor(sf::Color(sf::Color::White));
	Menu1.setCharacterSize(40);
	Menu1.setString(playerName1);

	Menu2.setPosition(340.f, 270.f);
	Menu2.setFillColor(sf::Color(sf::Color::White));
	Menu2.setCharacterSize(40);
	Menu2.setString(playerName2);

	Menu3.setPosition(0.f, 0.f);
	Menu3.setFillColor(sf::Color(sf::Color::White));
	Menu3.setCharacterSize(30);
	Menu3.setString("Tab to name other player");

	Menu4.setPosition(340.f, 100.f);
	Menu4.setFillColor(sf::Color(sf::Color::Red));
	Menu4.setCharacterSize(30);
	Menu4.setString("Type your character name: (Enter to Start)");

	while (true)
	{
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::TextEntered)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
					tabPressed++;
				if (tabPressed % 2 == 1)
				{
					// To not take the tab
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
					{
						// If backspace is pressed, erase the char
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (totalChar1 > 0))
							playerName1.erase(totalChar1--, 1);
						// Allow any char of the ASCII table
						else if ((totalChar1 <= 14) && (totalChar1 >= 0))
						{
							playerName1 += (char)Event.text.unicode;
							totalChar1++;
						}
						Menu1.setString(playerName1);
					}
				}
				else
				{
					// To not take the tab
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
					{
						// If backspace is pressed, erase the char
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (totalChar2 >= 0))
							playerName2.erase(totalChar2--, 1);
						// Allow any char of the ASCII table
						else if ((totalChar2 <= 14) && (totalChar2 >= -1))
						{
							playerName2 += (char)Event.text.unicode;
							totalChar2++;
						}
						Menu2.setString(playerName2);	
					}				
				}
				
			}
			// close button clicked
			if (Event.type == sf::Event::Closed)
				return false;

			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				// Play buttom pressed
				case sf::Keyboard::Return:
						Player::getInstance()->setIsMultiplayer(true);
						Player::getInstance()->setPlayer1Name(playerName1);
						Player::getInstance()->setPlayer2Name(playerName2);
						return true;
				default:
					break;
				}
			}
		}

		window.clear();

		window.draw(Menu1);
		window.draw(Menu2);
		window.draw(Menu3);
		window.draw(Menu4);
		
		window.display();
	}	
}

/************************************************************/
bool OpenMenu::continueGame()
{
	if (Save::getInstance()->Recover_save())
		return true;
	return false;
}

/************************************************************/
std::string OpenMenu::getPlayer1Name()
{
	return playerName1;
}

std::string OpenMenu::getPlayer2Name()
{
	return playerName2;
}

void OpenMenu::setPlayer1Name(std::string n1)
{
	playerName1 = n1;
}

void OpenMenu::setPlayer2Name(std::string n2)
{
	playerName2 = n2;
}

// To delete this method, first need to implement the rank system
bool OpenMenu::showNotImplementedYet(sf::RenderWindow& window)
{
	sf::Texture texture;
	if (!texture.loadFromFile("notImplementedYet.png"))
		exit(-1);
	sf::Sprite sprite;
	sprite.setTexture(texture);


	window.clear();
	window.draw(sprite);
	window.display();
    while (true)
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::MouseButtonPressed:
                case sf::Event::KeyPressed:
                return true;
                case sf::Event::Closed:
                    return false;
                default:;
            }
        }
    }
}