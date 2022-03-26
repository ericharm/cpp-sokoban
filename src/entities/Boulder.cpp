#include "Boulder.h"

Boulder::Boulder(int x, int y) {
  this->moveTo(x, y);
  this->character = '0';
  this->color = CyanColor;
  this->type = BoulderType;
};

bool Boulder::moveThrough(int x, int y, std::vector<std::shared_ptr<Entity>> entities) {
  int newX = this->x + x;
  int newY = this->y + y;
  for (std::shared_ptr<Entity> entity : entities) {
    bool collides = !this->is(entity) && entity->getX() == newX && entity->getY() == newY;
    if (collides) {
      if (entity->type == PitType) {
        this->remove();
        entity->remove();
        return true;
      }
      return false;
    }
  }

  this->moveBy(x, y);
  return true;
}
