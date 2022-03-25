#include "LineAndCharacterIterator.h"
#include <fstream>

LineAndCharacterIterator::LineAndCharacterIterator(std::vector<std::string> lines) {
  this->lines = lines;
}

LineAndCharacterIterator LineAndCharacterIterator::fromFile(std::string fileName) {
  std::ifstream file = std::ifstream(fileName);
  std::vector<std::string> lines;
  std::string line;
  while(std::getline(file, line)) lines.push_back(line);
  return LineAndCharacterIterator(lines);
}

void LineAndCharacterIterator::eachLineEachChar(ActionFn action) {
  int row = 0;
  for (std::string& line : this->lines) {
    int column = 0;
    row++;
    for (char& character: line) {
      column++;
      action(character, column, row);
    }
  }
}

