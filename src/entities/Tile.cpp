#include "Tile.h"

Tile::Tile(int x, int y) {
  this->x = x;
  this->y = y;
}

Tile::Tile() {
  this->x = 0;
  this->y = 0;
}

void Tile::moveBy(int x, int y) {
  this->x += x;
  this->y += y;
}

void Tile::moveTo(int x, int y) {
  this->x = x;
  this->y = y;
}

void Tile::render(WINDOW * win) const {
  mvwaddch(win, this->y, this->x, '.');
}
