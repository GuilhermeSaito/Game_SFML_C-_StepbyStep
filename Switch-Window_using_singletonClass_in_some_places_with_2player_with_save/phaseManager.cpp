#include "phaseManager.h"

#include "player.h"
#include "save.h"

PhaseManager* PhaseManager::p_instance = NULL;

PhaseManager::PhaseManager()
{
    spritePhase1.setTexture(*(Texture::getInstace()->getPhase1Texture()));
    spritePhase2.setTexture(*(Texture::getInstace()->getPhase2Texture()));

	menu1.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	menu2.setFont(*(Texture::getInstace()->getOpenMenuFont()));
	menu3.setFont(*(Texture::getInstace()->getOpenMenuFont()));
}

PhaseManager::~PhaseManager()
{
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
        return (Phase1(window));
    else
        return (Phase2(window));
}

int PhaseManager::Phase1(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 1" << endl; 
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            // Window closed
			if (event.type == sf::Event::Closed)
			{
				return -1;
			}
			//Key pressed
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				// Se for precionado o ESCs
				case sf::Keyboard::Escape:
					phaseSatate = escPressed(window);
					if (phaseSatate == -1 || phaseSatate == 3)
						return -1;
					else if (phaseSatate == 2)
					{
						Save::getInstance()->Save_save();
						return 1;
					}
					break;
				}
			}
        }
        window.clear();
		
		// Delete this
		window.draw(spritePhase1);
		
		Player::getInstance()->draw(window);
        window.display();
    }
}

int PhaseManager::Phase2(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 2" << endl;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            // Window closed
			if (event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				// Se for precionado o ESCs
				case sf::Keyboard::Escape:
					phaseSatate = escPressed(window);
					if (phaseSatate == -1 || phaseSatate == 3)
						return -1;
					else if (phaseSatate == 2)
					{
						Save::getInstance()->Save_save();
						return 1;
					}

					break;
				}
			}
        }
        window.clear();
		
		// Delete this
		window.draw(spritePhase2);

		Player::getInstance()->draw(window);
        window.display();
    }
}

/*
	return:
		1 - Continue - Dont do nothing
		2 - Save - Save the progress and go back to mainMenu(openMenu.cpp/.h)
		3 - Exit - Close the game without saving
		-1 - Exit - Game Closed
*/
int PhaseManager::escPressed(sf::RenderWindow& window)
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
			{
				return -1;
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
					if (menu == 1)
						return 1;
					else if (menu == 2)
						return 2;
					else 
						return 3;
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

void PhaseManager::setIsPhase1(bool p)
{
    isPhase1 = p;
}

bool PhaseManager::getIsPhase1()
{
	return isPhase1;
}