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
    bool collides = !this->is(entity) && entity->getX() == newX && entity->getY() == newY;
    if (collides) {
      if (entity->type == ExitType) {
        this->moveBy(x, y);
        this->victorious = true;
        return true;
      }

      bool squareWasVacated = entity->moveThrough(x, y, entities);
      if (squareWasVacated) {
        this->moveBy(x, y);
        return true;
      }
      return false;
    }
  }
  this->moveBy(x, y);
  return true;
}
