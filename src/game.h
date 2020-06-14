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
    void handle_input();
    /* void update(sf::Time delta_time); */
    void update();
    void draw();
    void configure_curses();

  private:
    WINDOW * win;
    Player player;
 
    // these will be handled by levels later,
    // which in turn will be handled by world class possibly
    // may not need scene nodes for tile based game
    // maybe this is a dynamically-sized array, we'll see
    Tile tiles [WINDOW_HEIGHT][WINDOW_WIDTH];
    /* World world; */
    /* GameInputHandler input_handler; */

};
#endif
