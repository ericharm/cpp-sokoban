#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    Player(int x, int y) {
      this->moveTo(x, y);
      this->character = '@';
      this->color = 1;
      this->typeName = "Player";
    };
};
#endif
