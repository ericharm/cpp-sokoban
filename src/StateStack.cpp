#include "StateStack.h"
#include <memory>
#include "states/MainMenu.h"

StateStack::StateStack() {
}

/* void StateStack::trade(State state) { */

/* } */

void StateStack::push(State* state) {
  this->states.push(std::unique_ptr<State>(state));
}

/* void StateStack::pop() { */

/* } */

bool StateStack::empty() {
  return this->states.empty();
}

std::unique_ptr<State>& StateStack::peek() {
   return states.top();
}
