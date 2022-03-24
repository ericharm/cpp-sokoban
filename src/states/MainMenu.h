#ifndef MAINMENU_H
#define MAINMENU_H
#include "../State.h"
#include "../Point.h"
#include <string>

struct MainMenuOption {
  std::string label;
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
    void drawCursor(WINDOW* win);
    void nextOption();
    void previousOption();
    void selectCurrentOption();
    int width = 7;
    int height = 10;
    MainMenuOption options [3];
    int currentOption;

};
#endif
