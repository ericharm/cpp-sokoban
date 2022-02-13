#ifndef STATE_H
#define STATE_H

class State {

  public:
    State() {};
    virtual ~State() = default;
    virtual void render(WINDOW * win) const = 0;
    virtual void handleInput() = 0;
    virtual void update() = 0;
};

#endif
