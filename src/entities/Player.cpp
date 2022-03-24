#include "Player.h"
#include "../Logger.h"
#include "../states/Victory.h"

Player::Player(int x, int y) {
  this->moveTo(x, y);
  this->character = '@';
  this->color = MagentaColor;
  this->type = PlayerType;
}

bool Player::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->type == WallType || entity->type == PitType) {
    return false;
  }

  /* if (entity->type == BoulderType) { */
  /*   if (entity->move */
  /* } */

  if (entity->type == ExitType) {
    this->victorious = true;
  }
  return true;
}
