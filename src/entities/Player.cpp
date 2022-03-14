#include "Player.h"

Player::Player(int x, int y) {
  this->moveTo(x, y);
  this->character = '@';
  this->color = MagentaColor;
  this->type = PlayerType;
}

bool Player::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->type == WallType) {
    return false;
  }
  return true;
}
