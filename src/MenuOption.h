#ifndef MENUOPTION_H
#define MENUOPTION_H
#include "Point.h"
#include <string>

struct MenuOption {
  std::string label;
  Point* location;
};

#endif // !MENUOPTION_H

