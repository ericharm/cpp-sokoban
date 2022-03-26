#ifndef PIT_H
#define PIT_H
#include <curses.h>
#include "../Entity.h"

class Pit: public Entity {

  public:
    Pit(int x, int y) {
      this->moveTo(x, y);
      this->character = '^';
      this->color = GreenColor;
      this->type = PitType;
    }
};
#endif
