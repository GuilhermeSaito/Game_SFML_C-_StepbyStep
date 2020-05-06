#include "phaseManager.h"

#include "player.h"

PhaseManager* PhaseManager::p_instance = NULL;

PhaseManager::PhaseManager()
{
    spritePhase1.setTexture(*(Texture::getInstace()->getPhase1Texture()));
    spritePhase2.setTexture(*(Texture::getInstace()->getPhase2Texture()));
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
					return 1;
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
					return 1;
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

void PhaseManager::setIsPhase1(bool p)
{
    isPhase1 = p;
}