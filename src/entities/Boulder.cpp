#include "Boulder.h"

Boulder::Boulder(int x, int y) {
  this->moveTo(x, y);
  this->character = '0';
  this->color = 2;
  this->typeName = "Boulder";
};

bool Boulder::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->typeName == "Boulder") {
    if (this->x < entity->getX()) entity->moveBy(1, 0);
    if (this->x > entity->getX()) entity->moveBy(-1, 0);
    if (this->y < entity->getY()) entity->moveBy(0, 1);
    if (this->y > entity->getY()) entity->moveBy(0, -1);
  }

  if (entity->typeName == "Wall") {
    return false;
  }
  return true;
}
