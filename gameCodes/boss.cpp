#include "boss.h"
#include "texture.h"

Boss::Boss()
{
  pos = sf::Vector2f(154*32, 6*32);

  sprite.setTexture(*(Texture::getInstace()->getFinalBossTextureLeft()));
  sprite.setScale(sf::Vector2f(2.f, 2.f));
  sprite.setTextureRect(sf::IntRect(650, 40, 46, 65));
  sprite.setPosition(this->pos.x, this->pos.y);
  rect.setSize(sf::Vector2f(43, 64));
  rect.setPosition(this->pos.x, this->pos.y);

  this->walkSpeed = 2.f;
  this->speed = sf::Vector2f(2.f, 1.f);
  this->points = 100;

  //healthBar muda a cada update, por isso só a cor agora
  healthBar.setFillColor(sf::Color::Red);

  this->hp = 100;
}

Boss::~Boss()
{
}

void Boss::movimentation(float posx)
{
  gravity();

  if (posx <= this->pos.x)
  {
    this->speed.x = -this->walkSpeed;
    this->pos.x += this->speed.x;
    sprite.setTexture(*(Texture::getInstace()->getFinalBossTextureLeft()));
    sprite.setScale(2.f, 2.f);
    sprite.setTextureRect(sf::IntRect(650, 40, 46, 65));
  }

  else if (posx > this->pos.x)
  {
    this->speed.x = this->walkSpeed;
    this->pos.x += this->speed.x;
    sprite.setTexture(*(Texture::getInstace()->getFinalBossTexture()));
    sprite.setTextureRect(sf::IntRect(7, 40, 46, 65));
    sprite.setScale(2.f,  2.f);
  }
    // for collision
    rect.setPosition(pos);
    sprite.setPosition(rect.getPosition());
}

void Boss::projectileMaker(float posxp, float posyp)
{
  this->projectiles.push_back(new Projectile(posxp, posyp, this->pos.x, this->pos.y));

  if (projectiles.size() == 4)
  {
    projectiles.erase(projectiles.begin()+1, projectiles.begin()+4);
  }
}

void Boss::update(float posx, Player1* player1, float *damageTimer)
{
  healthBar.setPosition(sprite.getPosition().x - 5, sprite.getPosition().y - 20);
  healthBar.setSize(sf::Vector2f(this->hp, 10.f));
  movimentation(posx);

  //updates the existing projectilesboss
  for (auto*project : this->projectiles)
  {
    project->update();

    if (project->getBoundBox().intersects(player1->getBoundBox()) && *damageTimer == 0)
    {
        player1->hp -= 10;
        (*damageTimer)++;
    }
  }
}

void Boss::render(sf::RenderTarget *target)
{
  for (auto*project : this->projectiles)
      project->render(target);

  target->draw(this->sprite);
  target->draw(this->healthBar);
}
