#include "config.h"
#include <curses.h>
#include "game.h"

Game::Game() : win(newwin(WINDOW_HEIGHT + 1, WINDOW_WIDTH + 1, 1, 1)) {
}

void Game::run() {
  wborder(win, 0, 0, 0, 0, 0, 0, 0, 0);
  noecho();
  cbreak();
  curs_set(0);
  wrefresh(win);

  // tiles
  for (int y = 0; y < WINDOW_HEIGHT - 1; y++) {
    for (int x = 0; x < WINDOW_WIDTH - 1; x++) {
      tiles[y][x] = Tile(x + 1, y + 1);
    }
  }
  
  // player
  player = Player();
  player.moveTo(5, 5);

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
  nodelay(stdscr, true);
  int ch = getch();
  switch (ch) {
    case 'j':
      player.move(0, 1);
      break;
    case 'k':
      player.move(0, -1);
      break;
    case 'h':
      player.move(-1, 0);
      break;
    case 'l':
      player.move(1, 0);
      break;
  }

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
  for (int y = 0; y < WINDOW_HEIGHT - 1; y++) {
    for (int x = 0; x < WINDOW_WIDTH - 1; x++) {
      tiles[y][x].draw(win);
    }
  }
  player.draw(win);

  wrefresh(win);
}
