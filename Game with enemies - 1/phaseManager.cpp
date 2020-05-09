#include "phaseManager.h"

#include "player.h"


PhaseManager* PhaseManager::p_instance = NULL;

void PhaseManager::iniEnemies()
{
  this->spawnTimerMax = 60.f;
  this->spawnTimer = this->spawnTimerMax;
}

PhaseManager::PhaseManager()
{
    srand(time(NULL));
    spritePhase1.setTexture(*(Texture::getInstace()->getPhase1Texture()));
    spritePhase2.setTexture(*(Texture::getInstace()->getPhase2Texture()));
    this->iniEnemies();
}

PhaseManager::~PhaseManager()
{
  for (auto* i : this->enemies)
    delete i;
}

PhaseManager* PhaseManager::getInstance()
{
    if (!p_instance)
        p_instance = new PhaseManager;
    return p_instance;
}

int PhaseManager::Start(sf::RenderWindow& window)
{
    if (isPhase1)
        return (Phase1(window));
    else
        return (Phase2(window));
}

int PhaseManager::Phase1(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 1" << endl;
    while (window.isOpen())
    {
      this->update(window);
      this->render(1, window);
    }
    return 1;
}

int PhaseManager::Phase2(sf::RenderWindow& window)
{
    cout << "[*] Loading Phase 2" << endl;
    while (window.isOpen())
    {
      this->update(window);
      this->render(2, window);
    }
    return 2;
}

void PhaseManager::setIsPhase1(bool p)
{
    isPhase1 = p;
}

void PhaseManager::updatePollEvents(sf::RenderWindow& window)
{
  sf::Event event;
  while (window.pollEvent(event))
  {
      // Window closed
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
      //Key pressed
      if (event.type == sf::Event::KeyPressed)
      {
        switch (event.key.code)
        {
        // Se for precionado o ESCs
        case sf::Keyboard::Escape:
          window.close();
          break;
        }
      }
  }
}

void PhaseManager::updateEnemies()
{
  this->spawnTimer += 0.5f;
  if (this->spawnTimer >= this->spawnTimerMax)
  {
    this->enemies.push_back(new Enemy(rand()%500, rand()%500, 30));
    this->spawnTimer = 0.f;
  }

  for (auto *enemy : this->enemies)
  {
    enemy->update();
  }

}

void PhaseManager::update(sf::RenderWindow& window)
{
  this->updatePollEvents(window);
  this->updateEnemies();
}

void PhaseManager::render(int i, sf::RenderWindow& window)
{
  window.clear();

  if (i == 1)
  {
  // Delete this
  window.draw(spritePhase1);
  }
  else
  window.draw(spritePhase2);

  for (auto *enemy : this->enemies)
  {
    enemy->render(&window);
  }

  Player::getInstance()->draw(window);
  window.display();
}
