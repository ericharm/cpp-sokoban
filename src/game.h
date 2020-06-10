#include "config.h"
#ifndef GAME_H
#define GAME_H
#include <curses.h>
#include "player.h"
#include "tile.h"
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
    Player player;
 
    // these will be handled by levels later,
    // which in turn will be handled by world class possibly
    // may not need scene nodes for tile based game
    // maybe this is a dynamically-sized array, we'll see
    Tile tiles [WINDOW_HEIGHT - 2][WINDOW_WIDTH - 2];
    /* World world; */
    /* GameInputHandler inputHandler; */

};
#endif
