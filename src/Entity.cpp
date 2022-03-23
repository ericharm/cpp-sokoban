#include "Entity.h"
#include "ScreenPosition.h"

Entity::Entity() {
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
  mvwaddch(win, this->y + ScreenPosition::yOffset, this->x + ScreenPosition::xOffset, this->character | COLOR_PAIR(this->color));
}

bool Entity::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->type == WallType) {
    return false;
  }
  return true;
}

void Entity::remove() {
  this->markedForRemoval = true;
}

bool Entity::is(std::shared_ptr<Entity> e) {
  return this->getX() == e->getX() && this->getY() == e->getY() && e->type == e->type;
}
