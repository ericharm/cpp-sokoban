#ifndef VICTORY_H
#define VICTORY_H
#include "../State.h"

class Victory: public State {

  public:
    Victory();
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    void returnToMainMenu();
    void writeMessage(WINDOW * win);
    int width = 10;
    int height = 1;

};
#endif
