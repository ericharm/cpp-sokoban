#ifndef STATE_H
#define STATE_H
#include <curses.h>

class State {

  public:
    State() {};
    virtual ~State() = default;
    virtual void render(WINDOW * win) = 0;
    virtual void handleInput(int key) = 0;
    virtual void update() = 0;
};

#endif
