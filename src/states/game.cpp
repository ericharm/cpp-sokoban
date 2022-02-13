#include "../Config.h"
#include "Game.h"

Game::Game() {
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x].moveTo(x, y);
    }
  }

  this->player.moveTo(5, 5);
}

void Game::handleInput() {
  int ch = getch();
  switch (ch) {
    case 'j':
      this->player.moveBy(0, 1);
      break;
    case 'k':
      this->player.moveBy(0, -1);
      break;
    case 'h':
      this->player.moveBy(-1, 0);
      break;
    case 'l':
      this->player.moveBy(1, 0);
      break;
  }
}

void Game::update() {
}

void Game::render(WINDOW* win) const {
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x].render(win);
    }
  }
  this->player.render(win);
}
