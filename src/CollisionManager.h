#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H
#include "Entity.h"
#include <memory>

class CollisionManager {

  public:
    CollisionManager();
    static std::unique_ptr<CollisionManager> forEntities(std::vector<std::shared_ptr<Entity>> entities);
    CollisionManager* move(std::shared_ptr<Entity> entity);
    // void to(int x, int y);
    bool by(int x, int y);

  private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::shared_ptr<Entity> current;
};

#endif
