#pragma once

#include <iostream>
#include "switchWindow.h"
#include "texture.h"

class OpenMenu: public SwitchWindow
{
private:
	sf::Event Event;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	sf::Text Menu4;
	sf::Sprite Sprite;

	std::string playerName1;
	std::string playerName2;

public:
	OpenMenu();
    ~OpenMenu();
	// Sobreescrevendo o método da classe herdada
    // Em vez de usar esse &, daria para utilizar o & na chamada do método e *, mas ai teria q usar * em todos...
	int Start(sf::RenderWindow& window) override;

	int showCharacterSelection(sf::RenderWindow& window);
	bool play1Player(sf::RenderWindow& window);
	bool play2Players(sf::RenderWindow& window);

	bool showNotImplementedYet(sf::RenderWindow& window);
};