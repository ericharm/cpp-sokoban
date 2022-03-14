#include "Boulder.h"

Boulder::Boulder(int x, int y) {
  this->moveTo(x, y);
  this->character = '0';
  this->color = CyanColor;
  this->type = BoulderType;
};

bool Boulder::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->type == WallType || entity->type == BoulderType) {
    return false;
  }
  return true;
}
