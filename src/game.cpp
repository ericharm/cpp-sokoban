#include <curses.h>
#include "game.h"
/* #include "command_queue.h" */

/* Game::Game() : window(sf::VideoMode(800, 600), "SFML Application"), world(window), inputHandler() { */
Game::Game() : win(newwin(10 + 1, 80 + 1, 1, 1)) {
  /* win = win; */
}

void Game::run() {
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);

  curs_set(0);
  wrefresh(win);

  int wd = 50;
  int ht = 8;

  char tiles [ht][wd];
  int y, x;
  for (y = 1; y < ht; y++) {
    for (x = 1; x < wd; x++) {
      mvwaddch(win, y, x, '.');
      tiles[y][x] = '.';
    }
  }

  wrefresh(win);

  /* sf::Clock clock; */
  /* sf::Time timePerFrame = sf::seconds(1.0f / 30.0f); */
  /* sf::Time timeSinceLastUpdate = sf::Time::Zero; */
  /* while (window.isOpen()) { */
  while (true) {
    /* timeSinceLastUpdate += clock.restart(); */
    /* while (timeSinceLastUpdate > timePerFrame) { */
    /* timeSinceLastUpdate -= timePerFrame; */
    handleInput();
    /* update(timePerFrame); */
    update();
    /* } */
    draw();
  }
}

void Game::handleInput() {
  /* CommandQueue& commands = world.getCommandQueue(); */
  /* sf::Event event; */
  /* while (window.pollEvent(event)) { */
  /*   inputHandler.handleEvent(event, commands); */
  /*   if (event.type == sf::Event::Closed) */
  /*     window.close(); */
  /* } */
  /* inputHandler.handleRealtimeInput(commands); */
}

void Game::update() {
/* void Game::update(sf::Time deltaTime) { */
  /* world.update(deltaTime); */
}

void Game::draw() {
    /* window.clear(); */
    /* world.draw(); */
    /* window.display(); */
}
