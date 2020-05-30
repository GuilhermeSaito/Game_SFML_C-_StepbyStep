#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>

class Projectile
{
private:
  sf::Sprite sprite;
  sf::RectangleShape rect;

  //speed an positioning
  float speedBase = 5.f;
  sf::Vector2f speed;
  sf::Vector2f pos;
  float angle;

public:
  Projectile(float posxp, float posyp, float posxe, float posye);
  ~Projectile();

  sf::FloatRect getBoundBox();

  void update();
  void render(sf::RenderTarget *target);
};
