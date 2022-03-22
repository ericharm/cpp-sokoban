#include "Pit.h"

Pit::Pit(int x, int y) {
  this->moveTo(x, y);
  this->character = '^';
  this->color = GreenColor;
  this->type = PitType;
};
