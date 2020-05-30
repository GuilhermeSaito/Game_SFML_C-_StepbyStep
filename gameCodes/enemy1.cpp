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
  sprite.setPosition(this->pos.x, this->pos.y);
  this->rect.setSize(sf::Vector2f(13.f, 32.f));
  this->rect.setPosition(this->pos.x, this->pos.y);

  this->walkSpeed = 3.f;
  this->speed = sf::Vector2f(3.f, 2.f);
  this->points = 10;

  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = hp;
}

Enemy1::~Enemy1()
{

}

void Enemy1::movimentation(float posx)
{
  gravity();

  if (posx <= this->pos.x)
  {
    this->speed.x = this->walkSpeed;
    this->pos.x -= this->speed.x;
    sprite.setTexture(*(Texture::getInstace()->getEnemy1Texture()));
    sprite.setScale(3.f, 3.f);
    sprite.setTextureRect(sf::IntRect(112, 0, 13, 23));
  }

  else if (posx > this->pos.x)
  {
    this->speed.x = this->walkSpeed;
    this->pos.x +=this->speed.x;
    sprite.setTexture(*(Texture::getInstace()->getEnemy1TextureRight()));
    sprite.setScale(3.f,  3.f);
    sprite.setTextureRect(sf::IntRect(52, 2, 13, 23));
  }

  else
  {
  }

  this->rect.setPosition(pos);
  this->sprite.setPosition(pos);
}

void Enemy1::update(float posx)
{
  healthBar.setSize(sf::Vector2f(hp, 10.f));
  healthBar.setPosition(sprite.getPosition().x - 5, sprite.getPosition().y - 20);
  movimentation(posx);
}

void Enemy1::render(sf::RenderTarget *target)
{
  target->draw(this->sprite);
  target->draw(this->healthBar);
}
