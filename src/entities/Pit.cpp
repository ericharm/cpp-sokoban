#include "Pit.h"

Pit::Pit(int x, int y) {
  this->moveTo(x, y);
  this->character = '^';
  this->color = GreenColor;
  this->type = PitType;
};


bool Pit::moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities) {
  return false;
}
