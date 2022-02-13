#ifndef ENTITY_H
#define ENTITY_H
#include <curses.h>

class Entity {

  public:
    Entity() {};
    virtual ~Entity() = default;
    virtual void render(WINDOW * win) const = 0;
    virtual void moveBy(int x, int y) = 0;
    virtual void moveTo(int x, int y) = 0;

  private:
    int x;
    int y;
};

#endif

