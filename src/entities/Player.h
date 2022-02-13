#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    Player();
    void moveBy(int x, int y);
};
#endif
