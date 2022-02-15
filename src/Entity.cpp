#include "Entity.h"

Entity::Entity() {
  this->x = 0;
  this->y = 0;
  this->color = 0;
  this->character = '?';
  this->typeName = "Entity";
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

bool Entity::moveBy(int x, int y, std::vector<std::shared_ptr<Entity>> entities) {
  int newX = this->x + x;
  int newY = this->y + y;
  for (std::shared_ptr<Entity>& entity : entities) {
    if (entity->getX() == newX && entity->getY() == newY) {
      entity->handleCollisionWith(this);
    }
  }

  this->x += x;
  this->y += y;
  return true;
}

int Entity::getY() {
  return this->y;
}

int Entity::getX() {
  return this->x;
}

void Entity::render(WINDOW * win) {
  mvwaddch(win, this->y, this->x, this->character | COLOR_PAIR(this->color));
}

bool Entity::handleCollisionWith(Entity* entity) {
  if (entity->typeName == "Boulder") {
    // now pass check collisions to next entity
    if (this->x < entity->getX()) entity->moveBy(-1, 0);
    if (this->x > entity->getX()) entity->moveBy(1, 0);
    if (this->y < entity->getY()) entity->moveBy(0, -1);
    if (this->y > entity->getY()) entity->moveBy(0, 1);
  }
  return true;
}
