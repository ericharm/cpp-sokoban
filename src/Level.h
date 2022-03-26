#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include "entities/Player.h"
#include <algorithm>

class Level {

  public:
    Level(std::string fileName);
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
