#include <iostream>
#include <stack>
#include <memory>
#include <curses.h>
#include "src/Config.h"
#include "src/State.h"
#include "src/states/Game.h"

void signalHandler(int signum) {
  std::cout << "Interrupt signal (" << signum << ") received.\n";
  endwin();
  // cleanup and close up stuff here
  // terminate program

  exit(signum);
}

 WINDOW * getCursesWindow() {
  initscr();
  WINDOW * win =  newwin(WINDOW_HEIGHT + 1, WINDOW_WIDTH + 1, 1, 1);
  noecho();
  keypad(stdscr, TRUE);
  cbreak();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  refresh();
  return win;
}

int main() {
  WINDOW * win = getCursesWindow();
  try {
    std::stack<std::unique_ptr<State>> states;
    states.push(std::unique_ptr<Game>(new Game()));
    while (!states.empty()) {
      std::unique_ptr<State>& state = states.top();
      wclear(win);
      state->render(win);
      wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
      wrefresh(win);
      state->handleInput(getch());
      state->update();
    }

  }
  catch (std::exception& e) {
    endwin(); // should also do this on sigint
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
  }
  return 0;
}
