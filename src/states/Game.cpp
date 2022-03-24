#include "Game.h"
#include <memory>

Game::Game() {
  curs_set(0);
  this->level = std::make_unique<Level>("./data/1.lvl");
}


Game::Game(std::string fileName) {
  curs_set(0);
  this->level = std::make_unique<Level>(fileName);
}

void Game::handleInput(int key) {
  this->level->handleInput(key);
}

void Game::update() {
  this->level->update();
}

void Game::render(WINDOW* win) {
  this->level->render(win);
}
