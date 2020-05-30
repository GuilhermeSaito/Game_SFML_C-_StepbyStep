#pragma once

#include "entity.h"
#include "projectile.h"
#include "player1.h"

class Boss: public Entity
{
public:
  float movementSpeed = 0;
  int attackDamage = 0;
  int direction = 0; //1-Up 2-Down 3-Left 4-Right
  int maxHp = 100;
  bool alive = true;
  bool canMoveUp = true;
  bool canMoveDown = true;
  bool canMoveLeft = true;
  bool canMoveRight = true;

  //projectiles
  std::vector<Projectile*> projectiles;

  Boss();
  ~Boss();

  void movimentation(float posx);

  void projectileMaker(float posxp, float posyp);

  void update(float posx, Player1* player1, float *damageTimer);
  void render(sf::RenderTarget *target);
};
