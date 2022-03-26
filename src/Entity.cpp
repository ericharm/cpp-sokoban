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

// returns true if the square the Entity was on has been vacated
bool Entity::pushTo(int x, int y, std::vector<std::shared_ptr<Entity>> entities) {
  return false;
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

void Entity::remove() {
  this->markedForRemoval = true;
}

