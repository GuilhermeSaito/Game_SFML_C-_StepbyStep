#pragma once

#include "entity.h"

class Enemy1: public Entity
{
public:
  float movementSpeed = 0;
  int attackDamage = 0;
  int direction = 0; //1-Up 2-Down 3-Left 4-Right
  int hp = 0;
  int maxHp = 10;
  int points = 0;
  bool alive = true;
  bool canMoveUp = true;
  bool canMoveDown = true;
  bool canMoveLeft = true;
  bool canMoveRight = true;

  Enemy1(float posx, float posy, int hp);
  ~Enemy1();

  //updates the movimentation of the enemy
  void movimentation(float posx);

  void update(float posx);
  void render(sf::RenderTarget *target);
};
