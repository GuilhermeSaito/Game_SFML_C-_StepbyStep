/* This .h is the responsible for the trade/switch of the windows. */

#pragma once

#include <SFML/Graphics.hpp>

class SwitchWindow
{
public:
    SwitchWindow() {};
    ~SwitchWindow() {};

    virtual int Start(sf::RenderWindow& window) = 0;
};