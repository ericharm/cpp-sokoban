#include <iostream>
/* #include <curses.h> */
#include "src/game.h"

int main() {
  initscr();

  /* int wd = 50; */
  /* int ht = 8; */

  /* WINDOW * win = newwin(ht + 1, wd + 1, 1, 1); */

  try {
    Game game = Game();
    game.run();
  }
  catch (std::exception& e) {
    endwin(); // should also do this on sigint
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
  }
  return 0;
}
