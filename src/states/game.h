#include "../config.h"
#ifndef GAME_H
#define GAME_H
#include "../player.h"
#include "../tile.h"
#include "../state.h"

class Game: public State {

  public:
    Game();
    void render(WINDOW * win) const;
    void handleInput();
    void update();

  private:
    // WINDOW * win;
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
