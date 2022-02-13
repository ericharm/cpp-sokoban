#ifndef TILE_H
#define TILE_H
#include <curses.h>
#include "../Entity.h"

class Tile: public Entity {

  public:
    Tile() {
      this->x = 0;
      this->y = 0;
      this->character = '.';
      this->color = 0;
    };

};
#endif
