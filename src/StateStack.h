#ifndef STATESTACK_H
#define STATESTACK_H
#include "State.h"
#include <memory>
#include <stack>

class StateStack {

  public:
    /* void trade(State state); */
    void push(State* state);
    /* void pop(); */
    bool empty();
    static StateStack* getInstance();
    std::unique_ptr<State>& peek();

  private:
    StateStack();
    std::stack<std::unique_ptr<State>> states;
    static StateStack* instance;

};
#endif
