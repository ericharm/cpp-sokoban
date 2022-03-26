#ifndef WALL_H
#define WALL_H
#include <curses.h>
#include "../Entity.h"

class Wall: public Entity {

  public:
    Wall(int x, int y);
    bool moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities);
};
#endif

