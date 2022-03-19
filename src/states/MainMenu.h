#ifndef MAINMENU_H
#define MAINMENU_H
#include "../State.h"
#include "../Point.h"
#include <string>

struct MenuOption {
  const char* label;
  Point* location;
};

class MainMenu: public State {

  public:
    MainMenu();
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    void drawTitle(WINDOW* win);
    void drawOptions(WINDOW* win);
    int width = 7;
    int height = 10;
    MenuOption options [3];

};
#endif
