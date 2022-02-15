#ifndef ENTITY_H
#define ENTITY_H
#include <curses.h>
#include <vector>
#include <string>

class Entity {

  public:
    Entity();
    Entity(int x, int y);
    virtual ~Entity() = default;
    virtual void render(WINDOW * win);
    virtual void moveBy(int x, int y);
    virtual bool moveBy(int x, int y, std::vector<std::shared_ptr<Entity>>);
    virtual void moveTo(int x, int y);
    virtual int getX();
    virtual int getY();
    std::string typeName; // replace with enum

  protected:
    int x;
    int y;
    int color = 0; // move this to an enum
    char character = '?';

  private:
    virtual bool handleCollisionWith(std::shared_ptr<Entity> entity);

};

#endif

