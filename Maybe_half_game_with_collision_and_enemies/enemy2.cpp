#include "enemy2.h"
#include "texture.h"

Enemy2::Enemy2(float posx, float posy, int hp)
{

  this->pos.x = posx;
  this->pos.y = posy;
  this->sprite.setTexture(*(Texture::getInstace()->getEnemy2Texture()));
  this->sprite.setScale(sf::Vector2f(3.f, 3.f));
  this->sprite.setTextureRect(sf::IntRect(112, 0, 13, 24));
  this->sprite.setPosition(this->pos.x, this->pos.y);

  this->speed = sf::Vector2f(2.f, 1.f);
  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = hp;
}

Enemy2::~Enemy2()
{
  for (Projectile* project : this->projectiles)
    delete project;
}

void Enemy2::movimentation(float posx)
{
  if (posx <= this->pos.x)
  {
    this->pos.x -= this->speed.x;
    this->sprite.setScale(3.f, 3.f);
    this->sprite.setTextureRect(sf::IntRect(112, 0, 13, 23));
    this->sprite.setPosition(this->pos.x, this->pos.y);
  }

  else if (posx > this->pos.x)
  {
    this->pos.x +=this->speed.x;
    this->sprite.setScale(-3.f,  3.f);
    this->sprite.setPosition(this->pos.x, this->pos.y);
  }

  else
  {
  }
}

void Enemy2::projectileMaker(float posxp, float posyp)
{
  this->projectiles.push_back(new Projectile(posxp, posyp, this->pos.x, this->pos.y));

  if (projectiles.size() == 4)
  {
    projectiles.erase(projectiles.begin()+1, projectiles.begin()+4);
  }
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

  target->draw(this->sprite);
  target->draw(this->healthBar);
}
