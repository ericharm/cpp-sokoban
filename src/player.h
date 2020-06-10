#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>

class Player {

  public:
    Player();
    void moveTo(int x, int y);
    void move(int x, int y);
    void draw(WINDOW * win);

  private:
    int x;
    int y;

};
#endif
