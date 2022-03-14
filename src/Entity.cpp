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

int Entity::getY() {
  return this->y;
}

int Entity::getX() {
  return this->x;
}

void Entity::render(WINDOW * win) {
  mvwaddch(win, this->y, this->x, this->character | COLOR_PAIR(this->color));
}

bool Entity::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->typeName == "Wall") {
    return false;
  }
  return true;
}

bool Entity::is(std::shared_ptr<Entity> e) {
  return this->getX() == e->getX() && this->getY() == e->getY() && e->typeName == e->typeName;
}
