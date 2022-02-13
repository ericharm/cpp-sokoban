#include "../Config.h"
#include "Game.h"
#include "../entities/Boulder.h"

Game::Game() {
  this->entities.push_back(std::unique_ptr<Boulder>(new Boulder(6, 6)));
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
