#ifndef BOULDER_H
#define BOULDER_H
#include <curses.h>
#include "../Entity.h"

class Boulder: public Entity {

  public:
    Boulder(int x, int y);
    bool moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities);

};
#endif
