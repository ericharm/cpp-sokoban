#ifndef ENTITY_H
#define ENTITY_H
#include <curses.h>
#include <vector>

class Entity {

  public:
    Entity();
    Entity(int x, int y);
    virtual ~Entity() = default;
    virtual void render(WINDOW * win);
    virtual void moveBy(int x, int y);
    virtual void moveTo(int x, int y);
    virtual void onCollidesWith(std::vector<Entity*>, int x, int y);

  protected:
    int x;
    int y;
    int color; // move this to an enum
    char character;
};

#endif

