#include <curses.h>
#include <memory>
#include "MainMenu.h"
#include "Victory.h"
#include "../ScreenPosition.h"
#include "../StateStack.h"
#include "../Color.h"

Victory::Victory() {
}

void Victory::handleInput(int key) {
  switch (key) {
    case '\n':
      this->returnToMainMenu();
      break;
  }
}

void Victory::update() {
}

void Victory::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2);
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2);
  this->writeMessage(win);
}

void Victory::writeMessage(WINDOW* win) {
  wattron(win, COLOR_PAIR(GreenColor));
  mvwprintw(
    win,
    ScreenPosition::yOffset,
    ScreenPosition::xOffset,
    "Well done!"
  );
  wattroff(win, COLOR_PAIR(GreenColor));
}

void Victory::returnToMainMenu() {
  StateStack* states = StateStack::getInstance();
  states->swap(std::make_unique<MainMenu>());
}
