#include "StateStack.h"
#include "State.h"
#include <memory>

StateStack* StateStack::instance = new StateStack();

StateStack::StateStack() {}

/* void StateStack::trade(State state) { } */

void StateStack::push(State* state) {
  this->states.push(std::unique_ptr<State>(state));
}

/* void StateStack::pop() { } */

bool StateStack::empty() {
  return this->states.empty();
}

std::unique_ptr<State>& StateStack::peek() {
   return states.top();
}

StateStack* StateStack::getInstance() {
  if (!instance) instance = new StateStack();
  return instance;
}
