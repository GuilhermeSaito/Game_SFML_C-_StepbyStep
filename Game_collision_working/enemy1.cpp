#include "enemy1.h"
#include "texture.h"

Enemy1::Enemy1(float posx, float posy, int hp)
{
  //takes the spawn sprite
  this->pos.x = posx;
  this->pos.y = posy;
  sprite.setTexture(*(Texture::getInstace()->getEnemy1Texture()));
  sprite.setScale(sf::Vector2f(3.f, 3.f));
  sprite.setTextureRect(sf::IntRect(112, 0, 13, 23));

  rect.setSize(sf::Vector2f(15, 20));

  this->speed = sf::Vector2f(3.f, 2.f);

  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = hp; 

  walkSpeed -= 5;
}

Enemy1::~Enemy1()
{

}

void Enemy1::movimentation(float posx)
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

void Enemy1::update(float posx)
{
  healthBar.setSize(sf::Vector2f(hp, 10.f));
  healthBar.setPosition(sprite.getPosition().x - 5, sprite.getPosition().y - 20);
  movimentation(posx);
}

void Enemy1::render(sf::RenderTarget *target)
{
  target->draw(this->rect);
  target->draw(this->healthBar);
}
