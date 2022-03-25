#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include "../State.h"

class Instructions: public State {

  public:
    Instructions();
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    void returnToMainMenu();
    void writeMessage(WINDOW * win);
    int width = 42;
    int height = 7;

};
#endif

