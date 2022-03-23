#include "MainMenu.h"
#include <curses.h>
#include "../ScreenPosition.h"
#include "../Color.h"
#include "../StateStack.h"
#include "../states/StageSelect.h"

enum MenuOptions {
  PlayOption,
  InstructionsOption,
  QuitOption
};

MainMenu::MainMenu() {
  curs_set(1);
  struct MenuOption play, instructions, quit;

  play.label = "Play";
  play.location = new Point(0, 4);

  instructions.label = "Instructions";
  instructions.location = new Point(0, 6);

  quit.label = "Exit";
  quit.location = new Point(0, 8);

  options[PlayOption] = play;
  options[InstructionsOption] = instructions;
  options[QuitOption] = quit;

  this->currentOption = 0;
}

void MainMenu::handleInput(int key) {
  switch (key) {
    case KEY_DOWN:
      this->nextOption();
      break;
    case KEY_UP:
      this->previousOption();
      break;
    case '\n':
      this->selectCurrentOption();
      break;
  }
}

void MainMenu::update() {
}

void MainMenu::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 2;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 2;

  this->drawTitle(win);
  this->drawOptions(win);
  this->drawCursor(win);
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
      option.label.c_str()
    );
  }
}

void MainMenu::drawCursor(WINDOW* win) {
  MenuOption* option = &this->options[this->currentOption];
  wmove(
    win,
    ScreenPosition::yOffset + option->location->y,
    ScreenPosition::xOffset + option->location->x - 2
  );
}

void MainMenu::nextOption() {
  if (this->currentOption < 2) {
    this->currentOption++;
  } else this->currentOption = 0;
}

void MainMenu::previousOption() {
  if (this->currentOption > 0) {
    this->currentOption--;
  } else this->currentOption = 2;
}

void MainMenu::selectCurrentOption() {
  switch (this->currentOption) {
    case PlayOption: {
      StateStack* states = StateStack::getInstance();
      states->swap(new StageSelect());
      break;
     }
    case InstructionsOption:
      break;
    case QuitOption:
      exit(0);
      break;
  }
}
