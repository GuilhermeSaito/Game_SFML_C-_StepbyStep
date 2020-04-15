#pragma once

#include <iostream>
#include "switchWindow.h"
#include "texture.h"

class OpenMenu: public SwitchWindow
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
	sf::Sprite Sprite;

public:
	OpenMenu();
    ~OpenMenu();
	// Sobreescrevendo o método da classe herdada
    // Em vez de usar esse &, daria para utilizar o & na chamada do método e *, mas ai teria q usar * em todos...
	int Start(sf::RenderWindow& window) override;
};