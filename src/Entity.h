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
    virtual bool handleCollisionWith(std::shared_ptr<Entity> entity);
    virtual bool is(std::shared_ptr<Entity>);
    virtual void moveTo(int x, int y);
    virtual void moveBy(int x, int y);
    virtual int getX();
    virtual int getY();
    EntityType type = NoneType;

  protected:
    int x = 0;
    int y = 0;
    Color color = NoColor;
    char character = '?';

  private:

};

#endif

