#include "Wall.h"

Wall::Wall(int x, int y) {
  this->moveTo(x, y);
  this->character = '#';
  this->color = NoColor;
  this->type = WallType;
}

bool Wall::moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities) {
  return false;
}
