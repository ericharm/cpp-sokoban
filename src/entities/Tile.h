#ifndef TILE_H
#define TILE_H
#include <curses.h>
#include "../Entity.h"

class Tile: public Entity {

  public:
    Tile();
    Tile(int x, int y);
    void render(WINDOW * win) const;
    void moveBy(int x, int y);
    void moveTo(int x, int y);

  private:
    int x;
    int y;

};
#endif
