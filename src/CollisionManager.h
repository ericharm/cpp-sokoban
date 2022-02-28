#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Entity.h"
#include "Level.h"
#include <memory>

class CollisionManager {

  public:
    static void moveEntity(Entity*);
    void throughLevel(std::unique_ptr<Level>);
    void to(int x, int y);
};

#endif

