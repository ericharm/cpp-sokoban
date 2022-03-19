#include "MainMenu.h"
#include <curses.h>
#include "../ScreenPosition.h"
#include "../Color.h"

MainMenu::MainMenu() {
  struct MenuOption play, instructions, quit;

  play.label = "Play";
  play.location = new Point(0, 4);

  instructions.label = "Instructions";
  instructions.location = new Point(0, 6);

  quit.label = "Exit";
  quit.location = new Point(0, 8);

  options[0] = play;
  options[1] = instructions;
  options[2] = quit;
}

void MainMenu::handleInput(int key) {
}

void MainMenu::update() {
}

void MainMenu::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 2;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 2;

  this->drawTitle(win);
  this->drawOptions(win);
}

void MainMenu::drawTitle(WINDOW* win) {
  wattron(win, COLOR_PAIR(GreenColor));
  mvwprintw(
    win,
    ScreenPosition::yOffset,
    ScreenPosition::xOffset,
    "Sokoban"
  );
  wattroff(win, COLOR_PAIR(GreenColor));

  mvwprintw(
    win,
    ScreenPosition::yOffset + 1,
    ScreenPosition::xOffset,
    "-------"
  );

}

void MainMenu::drawOptions(WINDOW* win) {
  for (MenuOption option : this->options) {
    mvwprintw(
      win,
      ScreenPosition::yOffset + option.location->y,
      ScreenPosition::xOffset + option.location->x,
      option.label
    );
  }
}
