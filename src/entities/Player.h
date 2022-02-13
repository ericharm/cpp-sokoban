#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    void render(WINDOW * win) const;

};
#endif
