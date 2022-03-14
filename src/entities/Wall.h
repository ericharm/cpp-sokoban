#ifndef WALL_H
#define WALL_H
#include <curses.h>
#include "../Entity.h"

class Wall: public Entity {

  public:
    Wall(int x, int y) {
      this->moveTo(x, y);
      this->character = '#';
      this->color = NoColor;
      this->type = WallType;
    };
};
#endif

