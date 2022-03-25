#include "Instructions.h"
#include "MainMenu.h"
#include "../LineAndCharacterIterator.h"
#include "../ScreenPosition.h"
#include "../StateStack.h"
#include "../Color.h"
#include <curses.h>
#include <fstream>
#include <string>
#include <vector>

Instructions::Instructions() {
  curs_set(0);
}

void Instructions::handleInput(int key) {
  switch (key) {
    case 27: // esc
      this->returnToMainMenu();
      break;
    case '\n':
      this->returnToMainMenu();
      break;
  }
}

void Instructions::update() {
}

void Instructions::render(WINDOW* win) {
  ScreenPosition::xOffset = (COLS / 2 - this->width / 2) - 2;
  ScreenPosition::yOffset = (LINES / 2 - this->height / 2) - 2;
  this->writeMessage(win);
}

void Instructions::writeMessage(WINDOW* win) {
  auto lines = LineAndCharacterIterator::fromFile("./data/instructions.txt");
  lines.eachLineEachChar([&](char character, int x, int y) {
    mvwaddch(
        win,
        y + ScreenPosition::yOffset,
        x + ScreenPosition::xOffset,
        character
    );
  });
}

void Instructions::returnToMainMenu() {
  StateStack* states = StateStack::getInstance();
  states->swap(std::make_unique<MainMenu>());
}
