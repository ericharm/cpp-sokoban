#include "../Config.h"
#include <ctime>
#include <curses.h>
#include "Game.h"

// Game::Game() : win(newwin(WINDOW_HEIGHT + 1, WINDOW_WIDTH + 1, 1, 1)) {
Game::Game() {
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x] = Tile(x, y);
    }
  }

  this->player = Player();
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

  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(win);
}
