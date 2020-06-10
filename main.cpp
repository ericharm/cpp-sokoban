#include <iostream>
/* #include <curses.h> */
#include "src/game.h"

void signalHandler(int signum) {
  std::cout << "Interrupt signal (" << signum << ") received.\n";
  endwin();
  // cleanup and close up stuff here  
  // terminate program  

  exit(signum);  
}

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
