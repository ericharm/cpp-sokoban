#include "Instructions.h"
#include "MainMenu.h"
#include "../LineAndCharacterIterator.h"
#include "../ScreenPosition.h"
#include "../StateStack.h"
#include "../Color.h"
#include "../Logger.h"
#include <curses.h>
#include <fstream>
#include <string>
#include <vector>

Instructions::Instructions() {
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
  std::ifstream file = std::ifstream("./data/instructions.txt");
  std::vector<std::string> lines;
  std::string line;
  while(std::getline(file, line)) {
    lines.push_back(line);
    Logger::log(line);
  }
  LineAndCharacterIterator iterator = LineAndCharacterIterator(lines);
  iterator.eachLineEachChar([&](char character, int y, int x) {
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
