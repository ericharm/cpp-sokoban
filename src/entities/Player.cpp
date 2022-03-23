#include "Player.h"
#include "../Logger.h"
#include "../StateStack.h"
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
  if (entity->type == ExitType) {
    StateStack* states = StateStack::getInstance();
    states->push(new Victory());
  }
  return true;
}
