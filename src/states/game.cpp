#include "../config.h"
#include <ctime>
#include <curses.h>
#include "game.h"

// Game::Game() : win(newwin(WINDOW_HEIGHT + 1, WINDOW_WIDTH + 1, 1, 1)) {
Game::Game() {
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x] = Tile(x, y);
    }
  }

  this->player = Player();
  this->player.move_to(5, 5);
}

void Game::handleInput() {
  int ch = getch();
  switch (ch) {
    case 'j':
      this->player.move(0, 1);
      break;
    case 'k':
      this->player.move(0, -1);
      break;
    case 'h':
      this->player.move(-1, 0);
      break;
    case 'l':
      this->player.move(1, 0);
      break;
  }
}

void Game::update() {
}

void Game::render(WINDOW* win) const {
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x].draw(win);
    }
  }
  this->player.draw(win);

  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(win);
}
