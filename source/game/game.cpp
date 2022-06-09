#include "game.hpp"

Game::Game(int cols, int rows, int scale) {
  srand(getpid());
  this->cols = cols;
  this->rows = rows;
  this->screen = new Screen(cols, rows, scale);
  this->board = new Board(cols, rows);
}

Game::~Game() {
  delete this->board;
  delete this->screen;
}

void Game::cycle() {
  screen->setDrawColor(0, 0, 0, 0);
  for (int i = 0; i < this->cols; i++) {
    for (int j = 0; j < this->rows; j++) {
      if (!this->board->getCellState(i, j))
        this->screen->render(i, j);
    }
  }

  screen->setDrawColor(158, 88, 243, 0);
  for (int i = 0; i < this->cols; i++) {
    for (int j = 0; j < this->rows; j++) {
      if (this->board->getCellState(i, j))
        this->screen->render(i, j);
    }
  }

  SDL_Delay(60);
  
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
