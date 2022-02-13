#include "Tile.h"

void Tile::render(WINDOW * win) const {
  mvwaddch(win, this->y, this->x, '.');
}
