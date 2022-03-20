#ifndef MAINMENU_H
#define MAINMENU_H
#include "../State.h"
#include "../MenuOption.h"
#include <string>

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
    MenuOption options [3];
    int currentOption;

};
#endif
