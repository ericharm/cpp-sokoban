#ifndef LINE_AND_CHARACTER_ITERATOR_H
#define LINE_AND_CHARACTER_ITERATOR_H
#include <functional>
#include <vector>
#include <string>

using ActionFn = std::function<void(char, int, int)>;

class LineAndCharacterIterator {
  public:
    LineAndCharacterIterator(std::vector<std::string> lines);
    static LineAndCharacterIterator fromFile(std::string fileName);
    void eachLineEachChar(ActionFn action);

  private:
    std::vector<std::string> lines;
};

#endif
