#ifndef BOULDER_H
#define BOULDER_H
#include <curses.h>
#include "../Entity.h"

class Boulder: public Entity {

  public:
    Boulder(int x, int y) {
      this->moveTo(x, y);
      this->character = '0';
      this->color = 2;
    };

};
#endif
