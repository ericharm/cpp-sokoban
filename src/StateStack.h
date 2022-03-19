#ifndef STATESTACK_H
#define STATESTACK_H
#include "State.h"
#include <memory>
#include <stack>

class StateStack {

  public:
    StateStack();
    /* void trade(State state); */
    /* void push(std::unique_ptr<State>& state); */
    void push(State* state);
    /* void pop(); */
    bool empty();
    std::unique_ptr<State>& peek();

  private:
    std::stack<std::unique_ptr<State>> states;
};
#endif // !STATESTACK_H
