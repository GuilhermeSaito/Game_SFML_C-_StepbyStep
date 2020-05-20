#include "projectile.h"
#include "texture.h"
#include <cmath>

Projectile::Projectile(float posxp, float posyp, float posxe, float posye)
{
  //initial position beeing enemies position
  this->pos.x = posxe + 16;
  this->pos.y = posye + 16;

  //initializating sprites
  this->sprite.setTexture(*(Texture::getInstace()->getProjectileTexture()));
  this->sprite.setScale(sf::Vector2f(2.3, 2.3));
  this->sprite.setTextureRect(sf::IntRect(148, 152, 12, 12));
  this->sprite.setPosition(this->pos.x, this->pos.y);

  //vector based (physics) math made to calculate the speed vector values
  this->angle = atan((abs(posyp-posye))/(abs(posxp-posxe)));
  this->speed.y = this->speedBase*sin(this->angle);
  this->speed.x = this->speedBase*cos(this->angle);

  if (posyp < posye)
    this->speed.y = this->speed.y*(-1);

  if (posxp < posxe)
    this->speed.x = this->speed.x*(-1);
}

Projectile::~Projectile()
{

}

void Projectile::update()
{
  this->pos.x += this->speed.x;
  this->pos.y += this->speed.y;
  this->sprite.setPosition(this->pos.x, this->pos.y);
}

void Projectile::render(sf::RenderTarget *target)
{
  target->draw(this->sprite);
}
