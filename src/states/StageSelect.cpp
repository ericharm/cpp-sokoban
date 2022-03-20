#include "StageSelect.h"
#include <curses.h>
#include <string>
#include "../ScreenPosition.h"
#include "../Color.h"
#include "../StateStack.h"
#include "../states/Game.h"

StageSelect::StageSelect() {
  for (int stage = 0; stage < 8; stage++) {
    std::string stageNumber = std::to_string(stage + 1);
    this->options[stage].label = "Stage " + stageNumber;
    int x = stage % 2 == 0 ? 0 : 10;
    int y = stage % 2 == 0 ? stage : stage -1;
    this->options[stage].location = new Point(x, y);
  }

  this->currentOption = 0;
}

void StageSelect::handleInput(int key) {
  switch (key) {
    case KEY_DOWN: {
      this->nextOption();
      this->nextOption();
      break;
    }
    case KEY_UP: {
      this->previousOption();
      this->previousOption();
      break;
    }
    case KEY_RIGHT:
      this->nextOption();
      break;
    case KEY_LEFT:
      this->previousOption();
      break;
    case '\n':
      this->selectCurrentOption();
      break;
  }
}

void StageSelect::update() {
}

void StageSelect::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 2;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 2;

  this->drawTitle(win);
  this->drawOptions(win);
  this->drawCursor(win);
}

void StageSelect::drawTitle(WINDOW* win) {
  wattron(win, COLOR_PAIR(GreenColor));
  mvwprintw(
    win,
    ScreenPosition::yOffset - 3,
    ScreenPosition::xOffset,
    "Stage Select"
  );
  wattroff(win, COLOR_PAIR(GreenColor));
}

void StageSelect::drawOptions(WINDOW* win) {
  for (MenuOption option : this->options) {
    mvwprintw(
      win,
      ScreenPosition::yOffset + option.location->y,
      ScreenPosition::xOffset + option.location->x,
      option.label.c_str()
    );
  }
}

void StageSelect::drawCursor(WINDOW* win) {
  MenuOption* option = &this->options[this->currentOption];
  wmove(
    win,
    ScreenPosition::yOffset + option->location->y,
    ScreenPosition::xOffset + option->location->x - 2
  );
}

void StageSelect::nextOption() {
  if (this->currentOption < 7) {
    this->currentOption++;
  } else this->currentOption = 0;
}

void StageSelect::previousOption() {
  if (this->currentOption > 0) {
    this->currentOption--;
  } else this->currentOption = 7;
}

void StageSelect::selectCurrentOption() {
  StateStack* states = StateStack::getInstance();
  states->swap(new Game());
}
