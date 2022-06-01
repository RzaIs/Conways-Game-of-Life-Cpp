#pragma once

#include <unistd.h>

#include "screen.hpp"
#include "board.hpp"

class Game {
private:
  int cols_width, rows_height;
  Screen * screen;
  Board * board;

  void cycle();
public:
  Game(int cols_width, int rows_height, int scale);
  ~Game();

  void start();
};
