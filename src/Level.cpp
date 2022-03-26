#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include "LineAndCharacterIterator.h"
#include "Logger.h"
#include "ScreenPosition.h"
#include "StateStack.h"
#include "entities/Boulder.h"
#include "entities/Player.h"
#include "entities/Pit.h"
#include "entities/Wall.h"
#include "entities/Exit.h"
#include "states/MainMenu.h"
#include "states/Victory.h"
#include "Level.h"

Level::Level(std::string fileName) {
  this->player = std::shared_ptr<Player>(std::make_shared<Player>(0, 0));
  this->loadFromFile(fileName);
}

void Level::handleInput(int key) {
  switch (key) {
    case KEY_DOWN:
      this->player->moveThrough(0, 1, this->entities);
      break;
    case KEY_UP:
      this->player->moveThrough(0, -1, this->entities);
      break;
    case KEY_LEFT:
      this->player->moveThrough(-1, 0, this->entities);
      break;
    case KEY_RIGHT:
      this->player->moveThrough(1, 0, this->entities);
      break;
    case 27: // ESC
      this->quitToMainMenu();
      break;
  }
}

void Level::update() {
  this->removeDeadEntities();
  this->proceedIfCompleted();
}

void Level::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 2;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 2;
  for (std::shared_ptr<Entity>& entity : entities) {
    entity->render(win);
  }

  this->player->render(win);
}

void Level::removeDeadEntities() {
  auto removers = std::remove_if(
      this->entities.begin(), this->entities.end(), std::mem_fn(&Entity::markedForRemoval)
  );
  this->entities.erase(removers, this->entities.end());
};

void Level::proceedIfCompleted() {
  if (this->player->victorious) {
    StateStack* states = StateStack::getInstance();
    states->swap(std::make_unique<Victory>());
  }
}

void Level::quitToMainMenu() {
    StateStack* states = StateStack::getInstance();
    states->swap(std::make_unique<MainMenu>());
}

void Level::loadFromFile(std::string fileName) {
  auto lines = LineAndCharacterIterator::fromFile(fileName);
  lines.eachLineEachChar([this](char character, int x, int y) {
    this->width = this->width < x ? x : this->width;
    this->height = this->height < y ? y : this->width;
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
