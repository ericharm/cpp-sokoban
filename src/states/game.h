#include "../Config.h"
#ifndef GAME_H
#define GAME_H
#include "../entities/Player.h"
#include "../entities/Tile.h"
#include "../State.h"

class Game: public State {

  public:
    Game();
    void render(WINDOW * win) const;
    void handleInput();
    void update();

  private:
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
