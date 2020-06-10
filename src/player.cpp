#include "player.h"

Player::Player() {
  this->x = 0;
  this->y = 0;
}

void Player::moveTo(int x, int y) {
  this->x = x;
  this->y = y;
}

void Player::move(int x, int y) {
  this->x += x;
  this->y += y;
}

void Player::draw(WINDOW * win) {
  mvwaddch(win, this->y, this->x, '@');
}
