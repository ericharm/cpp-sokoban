#ifndef STATESTACK_H
#define STATESTACK_H
#include "State.h"
#include <memory>
#include <stack>

class StateStack {

  public:
    void swap(std::unique_ptr<State> state);
    void push(std::unique_ptr<State> state);
    void pop();
    bool empty();
    static StateStack* getInstance();
    std::unique_ptr<State>& peek();

  private:
    StateStack();
    ~StateStack();
    std::stack<std::unique_ptr<State>> states;
    static StateStack* instance;

};
#endif
