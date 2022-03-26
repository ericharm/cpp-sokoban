#include "Player.h"
#include "../Logger.h"
#include "../states/Victory.h"

Player::Player(int x, int y) {
  this->moveTo(x, y);
  this->character = '@';
  this->color = MagentaColor;
  this->type = PlayerType;
}

bool Player::moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities) {
  int newX = this->x + x;
  int newY = this->y + y;
  for (std::shared_ptr<Entity> entity : entities) {
    bool collides = entity->getX() == newX && entity->getY() == newY;
    if (collides) {
      if (entity->moveThrough(x, y, entities)) {
        this->moveBy(x, y);
        return true;
      } else return this->handleCollisionWith(entity);
    }
  }
  this->moveBy(x, y);
  return true;
}

bool Player::handleCollisionWith(std::shared_ptr<Entity> entity) {
  if (entity->type == ExitType) {
    this->moveBy(x, y);
    this->victorious = true;
    return true;
  } else return false;
}
