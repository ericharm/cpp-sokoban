#ifndef BOULDER_H
#define BOULDER_H
#include <curses.h>
#include "../Entity.h"

class Boulder: public Entity {

  public:
    Boulder(int x, int y);
    bool pushTo(int x, int y, std::vector<std::shared_ptr<Entity>> entities);
    bool handleCollisionWith(std::shared_ptr<Entity> entity);

};
#endif
