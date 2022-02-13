#include "Player.h"

Player::Player() {
  this->x = 0;
  this->y = 0;
}

void Player::moveTo(int x, int y) {
  this->x = x;
  this->y = y;
}

void Player::moveBy(int x, int y) {
  this->x += x;
  this->y += y;
}

void Player::render(WINDOW * win) const {
  mvwaddch(win, this->y, this->x, '@' | COLOR_PAIR(1));
}
