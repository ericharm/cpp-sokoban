#include "StageSelect.h"
#include <curses.h>
#include <memory>
#include <string>
#include "../ScreenPosition.h"
#include "../Color.h"
#include "../StateStack.h"
#include "../states/Game.h"
#include "../states/MainMenu.h"

StageSelect::StageSelect() {
  for (int stage = 0; stage < 8; stage++) {
    std::string stageNumber = std::to_string(stage + 1);
    this->options[stage].label = "Stage " + stageNumber;
    int x = stage % 2 == 0 ? 0 : 10;
    int y = stage % 2 == 0 ? stage + 1 : stage;
    this->options[stage].location = Point(x, y);
    this->options[stage].fileName = "./data/" + stageNumber + ".lvl";
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
    case 27: // ESC
      this->back();
      break;
    case '\n':
      this->selectCurrentOption();
      break;
  }
}

void StageSelect::update() {
}

void StageSelect::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2);
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2);

  this->drawTitle(win);
  this->drawOptions(win);
  this->drawCursor(win);
}

void StageSelect::drawTitle(WINDOW* win) {
  wattron(win, COLOR_PAIR(GreenColor));
  mvwprintw(
    win,
    ScreenPosition::yOffset - 2,
    ScreenPosition::xOffset,
    "Stage Select"
  );
  wattroff(win, COLOR_PAIR(GreenColor));
  mvwprintw(
    win,
    ScreenPosition::yOffset - 1,
    ScreenPosition::xOffset,
    "------------"
  );

}

void StageSelect::drawOptions(WINDOW* win) {
  for (StageSelectOption option : this->options) {
    mvwprintw(
      win,
      ScreenPosition::yOffset + option.location.y,
      ScreenPosition::xOffset + option.location.x,
      option.label.c_str()
    );
  }
}

void StageSelect::drawCursor(WINDOW* win) {
  StageSelectOption* option = &this->options[this->currentOption];
  wmove(
    win,
    ScreenPosition::yOffset + option->location.y,
    ScreenPosition::xOffset + option->location.x - 2
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

void StageSelect::back() {
  StateStack* states = StateStack::getInstance();
  states->swap(std::make_unique<MainMenu>());
}

void StageSelect::selectCurrentOption() {
  std::string fileName = this->options[this->currentOption].fileName;
  StateStack* states = StateStack::getInstance();
  states->swap(std::make_unique<Game>(fileName));
}
