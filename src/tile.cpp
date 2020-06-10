#include "tile.h"

Tile::Tile(int x, int y) {
  this->x = x;
  this->y = y;
}

Tile::Tile() {
  x = 0;
  y = 0;
}

void Tile::draw(WINDOW * win) {
  mvwaddch(win, y, x, '.');
}
