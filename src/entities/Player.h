#ifndef PLAYER_H
#define PLAYER_H
#include <curses.h>
#include "../Entity.h"

class Player: public Entity {

  public:
    Player(int x, int y);
    bool handleCollisionWith(std::shared_ptr<Entity> entity);
    bool victorious = false;

};
#endif
