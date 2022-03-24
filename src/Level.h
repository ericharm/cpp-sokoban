#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include "CollisionManager.h"
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
    std::unique_ptr<CollisionManager> collisionManager;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::string> readLevel(std::string fileName);
    void loadFromFile(std::string fileName);
    void removeDeadEntities();
    void proceedIfCompleted();
    void quitToMainMenu();
};

#endif
