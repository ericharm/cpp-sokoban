#ifndef EXIT_H
#define EXIT_H
#include <curses.h>
#include "../Entity.h"

class Exit: public Entity {

  public:
    Exit(int x, int y);
    bool handleCollisionWith(std::shared_ptr<Entity> entity);

};
#endif

