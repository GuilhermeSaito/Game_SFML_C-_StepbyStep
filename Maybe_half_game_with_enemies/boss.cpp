#include "boss.h"
#include "texture.h"

Boss::Boss(float posx, float posy, int hp)
{
  this->pos.x = posx;
  this->pos.y = posy;
  sprite.setTexture(*(Texture::getInstace()->getFinalBossTexture()));
  sprite.setScale(sf::Vector2f(-2.f, 2.f));
  sprite.setTextureRect(sf::IntRect(7, 40, 43, 75));
  sprite.setPosition(this->pos.x, this->pos.y);

  this->speed = sf::Vector2f(2.f, 1.f);

  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = hp;
}

Boss::~Boss()
{

}

void Boss::movimentation(float posx)
{

  if (posx <= this->pos.x)
  {
    this->pos.x -= this->speed.x;
    sprite.setScale(-2.f, 2.f);
    sprite.setTextureRect(sf::IntRect(7, 40, 43, 75));
    sprite.setPosition(this->pos.x, this->pos.y);
  }

  else if (posx > this->pos.x)
  {
    this->pos.x +=this->speed.x;
    sprite.setScale(2.f,  2.f);
    sprite.setPosition(this->pos.x, this->pos.y);
  }
}

void Boss::projectileMaker(float posxp, float posyp)
{
  this->projectiles.push_back(new Projectile(posxp, posyp, this->pos.x, this->pos.y));

  if (projectiles.size() == 4)
  {
    projectiles.erase(projectiles.begin()+1, projectiles.begin()+4);
  }
}

void Boss::update(float posx)
{
  healthBar.setSize(sf::Vector2f(hp, 10.f));
  healthBar.setPosition(sprite.getPosition().x - 5, sprite.getPosition().y - 20);
  movimentation(posx);

  //updates the existing projectiles
  for (auto*project : this->projectiles)
    project->update();
}

void Boss::render(sf::RenderTarget *target)
{
  for (auto*project : this->projectiles)
      project->render(target);

  target->draw(this->sprite);
  target->draw(this->healthBar);
}
