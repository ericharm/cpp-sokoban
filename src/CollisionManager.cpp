#include "CollisionManager.h"

CollisionManager::CollisionManager() {
};

std::unique_ptr<CollisionManager> CollisionManager::forEntities(std::vector<std::shared_ptr<Entity>> entities) {
  CollisionManager* cm = new CollisionManager();
  cm->entities = entities;
  return std::unique_ptr<CollisionManager>(cm);
}

CollisionManager* CollisionManager::move(std::shared_ptr<Entity> entity) {
  this->current = entity;
  return this;
}

bool CollisionManager::by(int x, int y) {
  int newX = this->current->getX() + x;
  int newY = this->current->getY() + y;
  std::shared_ptr<Entity> original = this->current;
  for (std::shared_ptr<Entity>& entity : entities) {
    if (!entity->is(this->current) && entity->getX() == newX && entity->getY() == newY) {
      if (this->current->handleCollisionWith(entity)) {
        bool moved = this->move(entity)->by(x, y);
        if (moved) original->moveBy(x, y);
        return true;
      } else return false;
    }
  }

  current->moveBy(x, y);
  return true;

}
