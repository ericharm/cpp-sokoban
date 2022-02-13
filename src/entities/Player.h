#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    Player();
    void moveTo(int x, int y);
    void moveBy(int x, int y);
    void render(WINDOW * win) const;

  private:
    int x;
    int y;

};
#endif
