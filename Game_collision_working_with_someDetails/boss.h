#pragma once

#include "entity.h"
#include "projectile.h"

class Boss: public Entity
{
public:
  float movementSpeed = 0;
  int attackDamage = 10;
  int direction = 0; //1-Up 2-Down 3-Left 4-Right
  int hp = 0;
  int maxHp = 100;
  int points = 50;
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

  void update(float posx);
  void render(sf::RenderTarget *target);

  void reciveDamage(int d);
  bool bossDie();

  int getAttackDamage();

  int getBossPoint();
};
