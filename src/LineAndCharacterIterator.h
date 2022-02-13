#ifndef LINE_AND_CHARACTER_ITERATOR_H
#define LINE_AND_CHARACTER_ITERATOR_H
#include <vector>
#include <string> 

class LineAndCharacterIterator {
  public:
    LineAndCharacterIterator(std::vector<std::string> lines);
    void eachLineEachChar(void (*action) (char, int, int));

  private:
    std::vector<std::string> lines;
};

#endif
