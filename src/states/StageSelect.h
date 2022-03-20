#ifndef STAGESELECT_H
#define STAGESELECT_H
#include "../State.h"
#include "../MenuOption.h"
#include <string>

class StageSelect : public State {

  public:
    StageSelect();
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
    int width = 16;
    int height = 8;
    MenuOption options [8];
    int currentOption;

};
#endif
