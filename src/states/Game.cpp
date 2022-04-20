#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include "Game.h"
#include "../LineAndCharacterIterator.h"
#include "../ScreenPosition.h"
#include "../StateStack.h"
#include "../states/MainMenu.h"
#include "../states/Victory.h"
#include "../entities/AllEntities.h"

Game::Game(std::string fileName) {
  curs_set(0);
  this->player = std::shared_ptr<Player>(std::make_shared<Player>(0, 0));
  this->loadFromFile(fileName);
}

void Game::handleInput(int key) {
  switch (key) {
    case KEY_DOWN:
    case 's':
      this->player->pushTo(0, 1, this->entities);
      break;
    case KEY_UP:
    case 'w':
      this->player->pushTo(0, -1, this->entities);
      break;
    case KEY_LEFT:
    case 'a':
      this->player->pushTo(-1, 0, this->entities);
      break;
    case KEY_RIGHT:
    case 'd':
      this->player->pushTo(1, 0, this->entities);
      break;
    case 27: // ESC
      this->quitToMainMenu();
      break;
  }
}

void Game::update() {
  this->removeDeadEntities();
  this->proceedIfCompleted();
}

void Game::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 1;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 1;
  for (std::shared_ptr<Entity>& entity : entities) entity->render(win);
  this->player->render(win);
}

void Game::removeDeadEntities() {
  auto removers = std::remove_if(
      this->entities.begin(),
      this->entities.end(),
      std::mem_fn(&Entity::markedForRemoval)
  );
  this->entities.erase(removers, this->entities.end());
};

void Game::proceedIfCompleted() {
  if (this->player->victorious) {
    StateStack* states = StateStack::getInstance();
    states->swap(std::make_unique<Victory>());
  }
}

void Game::quitToMainMenu() {
    StateStack* states = StateStack::getInstance();
    states->swap(std::make_unique<MainMenu>());
}

void Game::loadFromFile(std::string fileName) {
  auto lines = LineAndCharacterIterator::fromFile(fileName);
  lines.eachLineEachChar([this](char character, int x, int y) {
    this->width = this->width < x ? x : this->width;
    this->height = this->height < y ? y : this->height;
    switch (character) {
      case '0':
        this->entities.push_back(std::make_shared<Boulder>(x, y));
        break;
      case '#':
        this->entities.push_back(std::make_shared<Wall>(x, y));
        break;
      case '^':
        this->entities.push_back(std::make_shared<Pit>(x, y));
        break;
      case 'X':
        this->entities.push_back(std::make_shared<Exit>(x, y));
        break;
      case '@':
        this->player->moveTo(x, y);
        break;
    }
  });
}
