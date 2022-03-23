#include "Exit.h"

Exit::Exit(int x, int y) {
  this->moveTo(x, y);
  this->character = 'X';
  this->color = YellowColor;
  this->type = ExitType;
}

bool Exit::handleCollisionWith(std::shared_ptr<Entity> entity) {
  return false;
}
