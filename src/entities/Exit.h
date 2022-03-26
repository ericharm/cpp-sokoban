#ifndef EXIT_H
#define EXIT_H
#include <curses.h>
#include "../Entity.h"

class Exit: public Entity {

  public:
    Exit(int x, int y) {
      this->moveTo(x, y);
      this->character = 'X';
      this->color = YellowColor;
      this->type = ExitType;
    }

};
#endif

