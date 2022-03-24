#include "StateStack.h"
#include "State.h"
#include <memory>

StateStack* StateStack::instance = new StateStack();

StateStack::StateStack() {
  states = std::stack<std::unique_ptr<State>>();
}

void StateStack::swap(std::unique_ptr<State> state) {
  this->pop();
  this->push(move(state));
}

void StateStack::push(std::unique_ptr<State> state) {
  this->states.push(move(state));
}

void StateStack::pop() {
  this->states.pop();
}

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
