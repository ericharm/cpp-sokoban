#ifndef ENTITY_H
#define ENTITY_H
#include <curses.h>
#include <memory>
#include <vector>
#include <string>
#include "EntityType.h"
#include "Color.h"

class Entity {

  public:
    Entity();
    Entity(int x, int y);
    virtual ~Entity() = default;
    virtual void render(WINDOW * win);
    virtual bool is(std::shared_ptr<Entity>);
    virtual void moveTo(int x, int y);
    virtual void moveBy(int x, int y);
    virtual bool moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities);
    virtual int getX();
    virtual int getY();
    virtual void remove();
    EntityType type = NoneType;
    bool markedForRemoval = false;

  protected:
    int x = 0;
    int y = 0;
    Color color = NoColor;
    char character = '?';

  private:

};

#endif

