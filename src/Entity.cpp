#include "Entity.h"

Entity::Entity() {
  this->x = 0;
  this->y = 0;
}

Entity::Entity(int x, int y) {
  this->x = x;
  this->y = y;
}

void Entity::moveTo(int x, int y) {
  this->x = x;
  this->y = y;
}

void Entity::moveBy(int x, int y) {
  this->x += x;
  this->y += y;
}
