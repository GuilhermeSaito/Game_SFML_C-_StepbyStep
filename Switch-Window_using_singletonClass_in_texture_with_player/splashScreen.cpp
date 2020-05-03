#include "splashScreen.h"

SplashScreen::SplashScreen()
{
    sprite.setTexture(*(Texture::getInstace()->getSplashScreenTexture()));
}

SplashScreen::~SplashScreen()
{
}

int SplashScreen::Start(sf::RenderWindow& window)
{
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
                return 1;
                case sf::Event::Closed:
                    return -1;
                default:;
            }
        }
    }   
}