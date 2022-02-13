#include <fstream>
#include "../Config.h"
#include "../entities/Boulder.h"
#include "../LineAndCharacterIterator.h"
#include "Game.h"

Game::Game() {
  this->placeEntities();
  this->player.moveTo(5, 5);
}

void Game::handleInput(int key) {
  switch (key) {
    case KEY_DOWN:
      this->player.moveBy(0, 1);
      break;
    case KEY_UP:
      this->player.moveBy(0, -1);
      break;
    case KEY_LEFT:
      this->player.moveBy(-1, 0);
      break;
    case KEY_RIGHT:
      this->player.moveBy(1, 0);
      break;
  }
}

void Game::update() {
}

void Game::render(WINDOW* win) {
  for (std::unique_ptr<Entity>& entity : entities) {
    entity->render(win);
  }

  this->player.render(win);
}

void Game::placeEntities() {
  std::ifstream file = std::ifstream("./data/1a.lvl");
  std::vector<std::string> lines; 
  std::string line; 
  while(std::getline(file, line)) lines.push_back(line); 

  int row = 0;
  for (std::string& line : lines) {
    int column = 0;
    row++;
    for (char& character: line) {
      column++;
      if (character == '0') {
        this->entities.push_back(std::unique_ptr<Boulder>(new Boulder(column, row)));
      }
    }
  }
}
