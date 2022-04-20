#ifndef GAME_H
#define GAME_H
#include "../State.h"
#include "../Entity.h"
#include "../entities/Player.h"
#include <algorithm>

class Game : public State {

  public:
    Game(std::string fileName);
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    int width;
    int height;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Entity>> entities;
    void loadFromFile(std::string fileName);
    void removeDeadEntities();
    void proceedIfCompleted();
    void quitToMainMenu();
};

#endif
