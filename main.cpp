#include <iostream>
#include <stack>
#include <curses.h>
#include "src/state.h"
#include "src/game.h"

void signalHandler(int signum) {
  std::cout << "Interrupt signal (" << signum << ") received.\n";
  endwin();
  // cleanup and close up stuff here  
  // terminate program  

  exit(signum);  
}

 WINDOW * configureCurses() {
  initscr();
  WINDOW * win =  newwin(WINDOW_HEIGHT + 1, WINDOW_WIDTH + 1, 1, 1);
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
  noecho();
  cbreak();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  refresh();
  return win;
}

int main() {
  WINDOW * win = configureCurses();
  try {
    std::stack<State*> states;
    Game game = Game();
    states.push(&game);
    // game.run();
    while (!states.empty()) {
      State* state = states.top();
      state->render(win);
      state->handleInput();
      state->update();
    }

  }
  catch (std::exception& e) {
    endwin(); // should also do this on sigint
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
  }
  return 0;
}
