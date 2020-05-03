#include "openMenu.h"

/*// SFGUI to use the Text Box Input
#include <>*/

OpenMenu::OpenMenu(void)
{
	Menu1.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu2.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu3.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu4.setFont(*(Texture::getInstace()->getOpenMenuFont()));

	Sprite.setTexture(*(Texture::getInstace()->getOpenMenuTexture()));
	// 								  Left, Top, Right, Bottom of the image.
	Sprite.setTextureRect(sf::IntRect(660, 200, 1260, 1000));
}

OpenMenu::~OpenMenu()
{
}

int OpenMenu::Start(sf::RenderWindow& window)
{
	bool Running = true;
	//sf::Texture Texture;
	//sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	int menu = 1;
    

	Menu1.setString("New Game");
	Menu1.setPosition({ 380.f, 200.f });
	Menu1.setCharacterSize(20);

	Menu2.setString("Continue Exist Game");
	Menu2.setPosition({ 380.f, 260.f });
	Menu2.setCharacterSize(20);

	Menu3.setString("Ranking");
	Menu3.setPosition({ 380.f, 320.f });
	Menu3.setCharacterSize(20);

	Menu4.setString("Exit");
	Menu4.setPosition({ 380.f, 380.f });
	Menu4.setCharacterSize(20);

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
					2 - Existing Game.
					3 - Ranking
					4 - Exit Program.
				*/
					if (menu == 1)
					{
						return showCharacterSelection(window);
					}
					else if (menu == 2 || menu == 3)
					{
						if (showNotImplementedYet(window))
							return (1);
						return -1;
					}
					else
					{
						//Let's get work...
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

int OpenMenu::showCharacterSelection(sf::RenderWindow& window)
{
	int menu = 1;

	Menu1.setString("1 Player");
	Menu1.setPosition({ 380.f, 220.f });
	Menu1.setCharacterSize(20);

	Menu2.setString("2 Players");
	Menu2.setPosition({ 380.f, 280.f });
	Menu2.setCharacterSize(20);

	while (true)
	{
		//Verifying events
	int alpha_max;
	int alpha_div;
	bool playing;
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
					1 - 1 Player
					2 - 2 Players
				*/
					if (menu == 1)
					{
						if (play1Player(window))
							return 2;
						return -1;
					}
					else
					{
						if (play2Players(window))
							return (2);
						return -1;
					}
					break;
				default:
					break;
				}
				// Don't letting the menu go for a invalid number.
				if (menu < 1)
					menu = 1;
				if (menu > 2)
					menu = 2;
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

		window.clear();
		
		window.draw(Menu1);
		window.draw(Menu2);

		window.display();
	}

	return -1;
}

// Input the name of the Player
bool OpenMenu::play1Player(sf::RenderWindow& window)
{
	int totalChar = 0;
	playerName1 = "";

	// Reutilizing the variable
	Menu1.setPosition(380.f, 280.f);
	Menu1.setFillColor(sf::Color(sf::Color::White));
	Menu1.setCharacterSize(60);
	Menu1.setString(playerName1);

	while (true)
	{
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::TextEntered)
			{
				// If backspace is pressed, erase the char
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
					playerName1.erase(totalChar--, 1);
				// Allow any char of the ASCII table
				else
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
					cout << "Key Pressed" << endl;
					cout << playerName1 << endl;
					return true;

					break;
				
				default:
					break;
				}
			}
		}
		window.clear();

		window.draw(Menu1);
		
		window.display();
	}
}

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
	Menu1.setCharacterSize(60);
	Menu1.setString(playerName1);
	Menu2.setPosition(340.f, 260.f);
	Menu2.setFillColor(sf::Color(sf::Color::White));
	Menu2.setCharacterSize(60);
	Menu2.setString(playerName2);
	Menu3.setPosition(0.f, 0.f);
	Menu3.setFillColor(sf::Color(sf::Color::White));
	Menu3.setCharacterSize(30);
	Menu3.setString("Tab to name other player");
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
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
							playerName1.erase(totalChar1--, 1);
						// Allow any char of the ASCII table
						else
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
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
							playerName2.erase(totalChar2--, 1);
						// Allow any char of the ASCII table
						else
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
		
		window.display();
	}	
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