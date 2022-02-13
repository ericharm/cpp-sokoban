#include "Player.h"

Player::Player() {
  this->x = 0;
  this->y = 0;
  this->character = '@';
  this->color = 1;
};

void Player::moveBy(int x, int y) {
  this->x += x;
  this->y += y;
}
