#include "Boulder.h"

Boulder::Boulder(int x, int y) {
  this->moveTo(x, y);
  this->character = '0';
  this->color = 2;
  this->typeName = "Boulder";
};

bool Boulder::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->typeName == "Wall" || entity->typeName == "Boulder") {
    return false;
  }
  return true;
}
