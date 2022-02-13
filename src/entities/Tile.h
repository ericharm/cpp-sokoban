#ifndef TILE_H
#define TILE_H
#include <curses.h>
#include "../Entity.h"

class Tile: public Entity {

  public:
    void render(WINDOW * win) const;

};
#endif
