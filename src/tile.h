#ifndef TILE_H
#define TILE_H
#include <curses.h>

class Tile {

  public:
    Tile();
    Tile(int x, int y);
    void draw(WINDOW * win) const;

  private:
    int x;
    int y;

};
#endif
