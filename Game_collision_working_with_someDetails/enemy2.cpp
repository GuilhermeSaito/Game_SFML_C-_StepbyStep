#include "enemy2.h"
#include "texture.h"

Enemy2::Enemy2(float posx, float posy, int hp)
{

  this->pos.x = posx;
  this->pos.y = posy;
  this->sprite.setTexture(*(Texture::getInstace()->getEnemy2Texture()));
  this->sprite.setScale(sf::Vector2f(3.f, 3.f));
  this->sprite.setTextureRect(sf::IntRect(112, 0, 13, 24));

  rect.setSize(sf::Vector2f(15, 25));

  this->speed = sf::Vector2f(2.f, 1.f);
  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = hp;

  walkSpeed -= 5;
}

Enemy2::~Enemy2()
{
  for (Projectile* project : this->projectiles)
    delete project;
}

void Enemy2::movimentation(float posx)
{
  gravity();

  if (posx <= this->pos.x)
  { 
    this->speed.x = -walkSpeed;
    this->pos.x += this->speed.x;
    sprite.setScale(-2.f, 2.f);
    sprite.setTextureRect(sf::IntRect(7, 40, 43, 75));
  }

  else if (posx > this->pos.x)
  {
    this->speed.x = walkSpeed;
    this->pos.x += this->speed.x;
    sprite.setScale(2.f,  2.f);
  }
    // for collision
    rect.setPosition(pos);
    sprite.setPosition(rect.getPosition());

}

void Enemy2::projectileMaker(float posxp, float posyp)
{
  this->projectiles.push_back(new Projectile(posxp, posyp, this->pos.x, this->pos.y));

  if (projectiles.size() == 4)
    projectiles.erase(projectiles.begin()+1, projectiles.begin()+4);
}

void Enemy2::update(float posx)
{
  healthBar.setSize(sf::Vector2f(hp, 10.f));
  healthBar.setPosition(sprite.getPosition().x - 5, sprite.getPosition().y - 20);
  movimentation(posx);

  //updates the existing projectiles
  for (auto*project : this->projectiles)
    project->update();
}

void Enemy2::render(sf::RenderTarget *target)
{
  for (auto*project : this->projectiles)
    project->render(target);

  target->draw(this->rect);
  target->draw(this->healthBar);
}

void Enemy2::reciveDamage(int d)
{
  hp -= d;
}

bool Enemy2::enemyDie()
{
  return (hp <= 0);
}

int Enemy2::getAttackDamage()
{
  return attackDamage;
}

int Enemy2::getEnemy2Point()
{
  return points;
}