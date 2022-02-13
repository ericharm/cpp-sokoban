#include "Player.h"

void Player::render(WINDOW * win) const {
  mvwaddch(win, this->y, this->x, '@' | COLOR_PAIR(1));
}
