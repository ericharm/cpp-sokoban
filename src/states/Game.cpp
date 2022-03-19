#include "Game.h"

Game::Game() {
  this->level = std::unique_ptr<Level>(new Level());
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