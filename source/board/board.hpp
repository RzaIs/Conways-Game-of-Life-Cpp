#pragma once

#include <iostream>
#include <vector>

#include "cell.hpp"
#include "point.hpp"

#define MAX_SIZE 1024

class Board {
private:
  // Fields
  int cols, rows;
  std::vector<std::vector<Cell>> oldTable, newTable;

  // Methods
  bool cellBelong(int col, int row);
  bool newCellState(Cell cell);

  void copyTable();
  void randomFill();

  int countAliveNeighbors(int col, int row);

  std::vector<Cell> getNeighbors(int col, int row);

public:
  Board(int cols, int rows);
  ~Board();

  bool getCellState(int col, int row);

  void generateNext();
};
