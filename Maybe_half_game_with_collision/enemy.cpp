#include "enemy.h"

Enemy::Enemy(float posx, float posy, int hp)
{
  //cria um retânguolo de 20x30
  rect.setSize(sf::Vector2f(20.f, 30.f));
  //preenche com uma cor
  rect.setFillColor(sf::Color::Blue);

  rect.setPosition(posx, posy);

  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = hp;
}

Enemy::~Enemy()
{

}

void Enemy::update()
{
  healthBar.setSize(sf::Vector2f(hp, 10.f));
  healthBar.setPosition(rect.getPosition().x - 10, rect.getPosition().y - 10);
}

void Enemy::render(sf::RenderTarget *target)
{
  target->draw(this->rect);

}
