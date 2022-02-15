#ifndef LEVEL_H
#define LEVEL_H
#include "Entity.h"
#include "entities/Player.h"

class Level {

  public:
    Level();
    void render(WINDOW * win);
    void handleInput(int key);
    void update();

  private:
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::string> readLevel(std::string fileName); 
    void placeEntities();
};

#endif
