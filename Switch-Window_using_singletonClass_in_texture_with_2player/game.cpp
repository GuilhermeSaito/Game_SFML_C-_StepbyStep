#include "game.h"
//#include "texture.h"
#include "player.h"

Game::Game()
{
	// Delete this
	backGroundSprite.setTexture(*(Texture::getInstace()->getBackGroundTexture()));
}

Game::~Game()
{
}

int Game::Start(sf::RenderWindow& window)
{
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
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
					return (1);
					break;
				}
			}
        }
        window.clear();
		
		// Delete this
		window.draw(backGroundSprite);

		Player::getInstance()->draw(window);
        window.display();
    }
}