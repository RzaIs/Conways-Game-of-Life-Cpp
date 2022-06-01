#include "game.hpp"

Game::Game(int cols_width, int rows_height, int scale) {
  srand(getpid());
  this->cols_width = cols_width;
  this->rows_height = rows_height;
  this->screen = new Screen(cols_width, rows_height, scale);
  this->board = new Board(cols_width, rows_height);
}

Game::~Game() {
  delete this->board;
  delete this->screen;
}

void Game::cycle() {
  screen->setDrawColor(30, 30, 30, 255);
  for (int i = 0; i < this->cols_width; i++) {
    for (int j = 0; j < this->rows_height; j++) {
      if (!this->board->getCellState(i, j))
        this->screen->render(i, j);
    }
  }

  screen->setDrawColor(158, 88, 243, 255);
  for (int i = 0; i < this->cols_width; i++) {
    for (int j = 0; j < this->rows_height; j++) {
      if (this->board->getCellState(i, j))
        this->screen->render(i, j);
    }
  }
  // usleep(200000);
  this->board->generateNext();
}

void Game::start() {
  SDL_Event event;
  bool gameRunning = true;

  while (gameRunning) {

    if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
      gameRunning = false;
    
    screen->clear();

    this->cycle();

    screen->display();
  }
  SDL_Quit();
}
