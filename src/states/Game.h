#ifndef GAME_H
#define GAME_H
#include "../State.h"
#include "../Level.h"

class Game: public State {

  public:
    Game();
    Game(std::string fileName);
    static Game fromFile(std::string fileName);
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    std::unique_ptr<Level> level;
};
#endif
