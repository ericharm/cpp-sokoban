#include "Player.h"

Player::Player(int x, int y) {
  this->moveTo(x, y);
  this->character = '@';
  this->color = 1;
  this->typeName = "Player";
}

bool Player::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->typeName == "Wall") {
    return false;
  }
  return true;
}
