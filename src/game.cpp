#include "config.h"
#include <ctime>
#include <curses.h>
#include "game.h"

Game::Game() : win(newwin(WINDOW_HEIGHT + 1, WINDOW_WIDTH + 1, 1, 1)) {
}

void Game::run() {
  configure_curses();

  // tiles
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x] = Tile(x, y);
    }
  }
  
  // player
  this->player = Player();
  this->player.move_to(5, 5);


  time_t t = time(NULL);
  double time_per_frame = 1 / 30;

  while (true) {
    time_t now = time(NULL);
    double delta_time = difftime(now, t);
    if (delta_time >= time_per_frame) {
      t = now;
      update();
      draw();
    }
    handle_input();
  }
}

void Game::handle_input() {
  int ch = getch();
  switch (ch) {
    case 'j':
      this->player.move(0, 1);
      break;
    case 'k':
      this->player.move(0, -1);
      break;
    case 'h':
      this->player.move(-1, 0);
      break;
    case 'l':
      this->player.move(1, 0);
      break;
  }

  /* CommandQueue& commands = world.getCommandQueue(); */
  /* sf::Event event; */
  /* while (window.poll_event(event)) { */
  /*   inputHandler.handle_event(event, commands); */
  /*   if (event.type == sf::Event::Closed) */
  /*     window.close(); */
  /* } */
  /* input_handler.handleRealtimeInput(commands); */
}

void Game::update() {
/* void Game::update(sf::Time delta_time) { */
  /* world.update(deltaTime); */
}

void Game::draw() {
  for (int y = 0; y < WINDOW_HEIGHT; y++) {
    for (int x = 0; x < WINDOW_WIDTH; x++) {
      this->tiles[y][x].draw(win);
    }
  }
  this->player.draw(win);

  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(win);
}

void Game::configure_curses() {
  /* wborder(win, 0, 0, 0, 0, 0, 0, 0, 0); */
  noecho();
  cbreak();
  curs_set(0);
  start_color();
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  refresh();
}
