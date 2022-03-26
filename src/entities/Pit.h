#ifndef PIT_H
#define PIT_H
#include <curses.h>
#include "../Entity.h"

class Pit: public Entity {

  public:
    Pit(int x, int y);
    bool moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities);

};
#endif
