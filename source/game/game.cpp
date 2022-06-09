#include "game.hpp"

Game::Game(int cols, int rows) {
  srand(getpid());
  this->cols = cols;
  this->rows = rows;
  this->board = new Board(cols, rows);
  this->ansiPrinter = new AnsiPrinter();
}

Game::~Game() {
  delete this->board;
  delete this->ansiPrinter;
}

void Game::cycle() {
  for (int i = 0; i < this->rows; i++) {
    std::cout << std::endl;
    for (int j = 0; j < this->cols; j++) {
      ansiPrinter->print(this->board->getCellState(j, i));
    }
  }

  usleep(300000);
  
  this->board->generateNext();
}

void Game::start() {

  while (true) {

    ansiPrinter->clear();

    this->cycle();
  }
}