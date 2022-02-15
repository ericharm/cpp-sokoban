#include "Player.h"

Player::Player(int x, int y) {
  this->moveTo(x, y);
  this->character = '@';
  this->color = 1;
  this->typeName = "Player";
}

bool Player::handleCollisionWith(std::shared_ptr<Entity> entity) {
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
