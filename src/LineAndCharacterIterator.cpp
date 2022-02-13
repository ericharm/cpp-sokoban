#include "LineAndCharacterIterator.h"

LineAndCharacterIterator::LineAndCharacterIterator(std::vector<std::string> lines) {
  this->lines = lines;
}

void LineAndCharacterIterator::eachLineEachChar(void (*action) (char, int, int)) {
  int row = 0;
  for (std::string& line : this->lines) {
    int column = 0;
    row++;
    for (char& character: line) {
      column++;
      action(character, row, column);
    }
  }
}

