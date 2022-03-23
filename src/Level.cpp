#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>
#include <string>
#include "Logger.h"
#include "ScreenPosition.h"
#include "entities/Boulder.h"
#include "entities/Player.h"
#include "entities/Pit.h"
#include "entities/Wall.h"
#include "Level.h"

Level::Level(std::string fileName) {
  this->player = std::shared_ptr<Player>(new Player(0, 0));
  this->loadFromFile(fileName);
  this->collisionManager = CollisionManager::forEntities(&this->entities);
}

void Level::handleInput(int key) {
  switch (key) {
    case KEY_DOWN:
      this->collisionManager->move(this->player)->by(0, 1);
      break;
    case KEY_UP:
      this->collisionManager->move(this->player)->by(0, -1);
      break;
    case KEY_LEFT:
      this->collisionManager->move(this->player)->by(-1, 0);
      break;
    case KEY_RIGHT:
      this->collisionManager->move(this->player)->by(1, 0);
      break;
  }
}

void Level::update() {
  auto removers = std::remove_if(
      this->entities.begin(), this->entities.end(), std::mem_fn(&Entity::markedForRemoval)
  );
  this->entities.erase(removers, this->entities.end());
}

void Level::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 2;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 2;
  for (std::shared_ptr<Entity>& entity : entities) {
    entity->render(win);
  }

  this->player->render(win);
}

std::vector<std::string> Level::readLevel(std::string fileName) {
  std::ifstream file = std::ifstream(fileName);
  std::vector<std::string> lines;
  std::string line;
  while(std::getline(file, line)) lines.push_back(line);
  return lines;
}

void Level::loadFromFile(std::string fileName) {
  std::vector<std::string> fileData = this->readLevel(fileName);

  int row = 0;
  for (std::string& line : fileData) {
    int column = 0;
    row++;
    if (row > this->height) this->height = row;
    for (char& character: line) {
      column++;
      if (column > this->width) this->width = column;
      switch (character) {
        case '0':
          this->entities.push_back(std::shared_ptr<Boulder>(new Boulder(column, row)));
          break;
        case '#':
          this->entities.push_back(std::shared_ptr<Wall>(new Wall(column, row)));
          break;
        case '^':
          this->entities.push_back(std::shared_ptr<Pit>(new Pit(column, row)));
          break;
        case '@':
          this->player->moveTo(column, row);
          break;
      }
    }
  }
}
