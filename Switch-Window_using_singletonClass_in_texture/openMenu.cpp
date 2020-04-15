#include "openMenu.h"

OpenMenu::OpenMenu(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;

	Sprite.setTexture(*(Texture::getInstace()->getOpenMenuTexture()));
	// 								  Left, Top, Right, Bottom of the image.
	Sprite.setTextureRect(sf::IntRect(660, 200, 1260, 1000));
}

OpenMenu::~OpenMenu()
{
}

int OpenMenu::Start(sf::RenderWindow& window)
{
	sf::Event Event;
	bool Running = true;
	//sf::Texture Texture;
	//sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;
    
	Menu1.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu1.setCharacterSize(20);
	Menu1.setString("Play");
	Menu1.setPosition({ 380.f, 200.f });

	Menu2.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	Menu2.setPosition({ 380.f, 260.f });

	Menu3.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	Menu3.setCharacterSize(20);
	Menu3.setString("Continue");
	Menu3.setPosition({ 380.f, 180.f });

	if (playing)
	{
		alpha = alpha_max;
	}

	while (Running)
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
					menu = 0;
					break;
				case sf::Keyboard::Down:
					menu = 1;
					break;
                // Keyboard::Return = Aperto o Enter
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						//Let's get play !
						playing = true;
						return (1);
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
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha<alpha_max)
		{
			alpha++;
		}
		//Sprite.setFillColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)
		{
			Menu1.setFillColor(sf::Color(255, 0, 0, 255));
			Menu2.setFillColor(sf::Color(255, 255, 255, 255));
			Menu3.setFillColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			Menu1.setFillColor(sf::Color(255, 255, 255, 255));
			Menu2.setFillColor(sf::Color(255, 0, 0, 255));
			Menu3.setFillColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen
		window.clear();
		//Drawing
		window.draw(Sprite);
		if (alpha == alpha_max)
		{
			if (playing)
			{
				window.draw(Menu3);
			}
			else
			{
				window.draw(Menu1);
			}
			window.draw(Menu2);
		}
		window.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}