#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    Player() {
      this->x = 0;
      this->y = 0;
      this->character = '@';
      this->color = 1;
    }
};
#endif
