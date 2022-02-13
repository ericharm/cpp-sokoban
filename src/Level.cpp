#include <fstream>
#include "Config.h"
#include "entities/Boulder.h"
#include "entities/Player.h"
#include "Level.h"

Level::Level() {
  this->player = std::unique_ptr<Player>(new Player());
  this->placeEntities();
}

void Level::handleInput(int key) {
  switch (key) {
    case KEY_DOWN:
      this->player->moveBy(0, 1);
      break;
    case KEY_UP:
      this->player->moveBy(0, -1);
      break;
    case KEY_LEFT:
      this->player->moveBy(-1, 0);
      break;
    case KEY_RIGHT:
      this->player->moveBy(1, 0);
      break;
  }
}

void Level::update() {
}

void Level::render(WINDOW* win) {
  for (std::unique_ptr<Entity>& entity : entities) {
    entity->render(win);
  }

  this->player->render(win);
}

std::vector<std::string> Level::readLevel(std::string fileName) {
  std::ifstream file = std::ifstream("./data/1a.lvl");
  std::vector<std::string> lines; 
  std::string line; 
  while(std::getline(file, line)) lines.push_back(line); 

  // does this leak memory?
  return lines;
}

void Level::placeEntities() {
  std::vector<std::string> fileData = this->readLevel("./data/1a.lvl");

  int row = 0;
  for (std::string& line : fileData) {
    int column = 0;
    row++;
    for (char& character: line) {
      column++;
      switch (character) {
        case '0':
          this->entities.push_back(std::unique_ptr<Boulder>(new Boulder(column, row)));
          break;
        case '@':
          this->player->moveTo(column, row);
          break;
      }
    }
  }
}
