#pragma once

#include "entity.h"
#include "projectile.h"

class Boss: public Entity
{
public:
  float movementSpeed = 0;
  int attackDamage = 0;
  int direction = 0; //1-Up 2-Down 3-Left 4-Right
  int hp = 0;
  int maxHp = 100;
  int points = 0;
  bool alive = true;
  bool canMoveUp = true;
  bool canMoveDown = true;
  bool canMoveLeft = true;
  bool canMoveRight = true;

  //projectiles
  std::vector<Projectile*> projectiles;

  Boss(float posx, float posy, int hp);
  Boss();
  ~Boss();

  void movimentation(float posx);

  void projectileMaker(float posxp, float posyp);

  void update(float posx);
  void render(sf::RenderTarget *target);
};
