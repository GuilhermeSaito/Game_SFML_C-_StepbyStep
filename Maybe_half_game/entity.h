#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
  sf::RectangleShape rect;
  sf::RectangleShape healthBar;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Vector2f speed;
  sf::Vector2f pos;
  bool onGround;
  bool right;

  void jump(bool& ground, sf::Vector2f& speed, sf::Vector2f& pos);

public:
    Entity();
    ~Entity();
};