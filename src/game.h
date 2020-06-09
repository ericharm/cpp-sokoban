#ifndef GAME_H
#define GAME_H
#include <curses.h>
/* #include <SFML/Graphics.hpp> */
/* #include "world.h" */
/* #include "game_input_handler.h" */

class Game {

  public:
    Game();
    void run();

  private:
    void handleInput();
    /* void update(sf::Time deltaTime); */
    void update();
    void draw();

  private:
    WINDOW * win;
    /* World world; */
    /* GameInputHandler inputHandler; */

};
#endif
