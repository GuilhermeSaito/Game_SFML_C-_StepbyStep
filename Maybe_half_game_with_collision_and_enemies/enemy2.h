#pragma once

#include "entity.h"
#include "projectile.h"
#include <vector>

class Enemy2: public Entity
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

  //projectiles
  std::vector<Projectile*> projectiles;

  Enemy2(float posx, float posy, int hp);
  ~Enemy2();

  //updates the movimentation of the enemy
  void movimentation(float posx);

  //updates new projectiles
  void projectileMaker(float posxp, float posyp);

  void update(float posx);
  void render(sf::RenderTarget *target);
};
