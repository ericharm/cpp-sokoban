#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    Player(int x, int y);
    bool pushTo(int x, int y, std::vector<std::shared_ptr<Entity>> entities);
    bool handleCollisionWith(std::shared_ptr<Entity> entity);
    bool victorious = false;

};
#endif
