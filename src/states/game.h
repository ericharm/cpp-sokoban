#ifndef GAME_H
#define GAME_H
#include <vector>
#include "../Config.h"
#include "../Entity.h"
#include "../State.h"
#include "../entities/Player.h"


class Game: public State {

  public:
    Game();
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    Player player;
    std::vector<std::unique_ptr<Entity>> entities;
};
#endif