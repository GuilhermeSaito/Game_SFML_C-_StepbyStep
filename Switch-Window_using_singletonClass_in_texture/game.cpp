#include "game.h"

Game::Game()
{
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
					return (0);
					break;
				}
			}
        }
        window.clear();

        player1.draw(window);
        window.display();
    }

	/*
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
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
					return (0);
					break;
				}
			}
        }

        window.clear();
        window.draw(shape);
        window.display();
    }*/
}