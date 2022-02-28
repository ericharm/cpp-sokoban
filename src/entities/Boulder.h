#ifndef BOULDER_H
#define BOULDER_H
#include <curses.h>
#include "../Entity.h"

class Boulder: public Entity {

  public:
    Boulder(int x, int y);
    bool handleCollisionWith(std::shared_ptr<Entity> entity);

};
#endif
