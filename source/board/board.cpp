#include "board.hpp"

Board::Board(int cols, int rows) {
  this->cols = cols;
  this->rows = rows;
  this->randomFill();
}

Board::~Board() {}

bool Board::cellBelong(int col, int row) {
  return (
    col >= 0 && col < this->cols && 
    row >= 0 && row < this->rows
  );
}

bool Board::getCellState(int col, int row) {
  return this->oldTable
    .at(col)
    .at(row)
    .getIsAlive();
}

void Board::copyTable() {

  for (std::vector<Cell> & subVector : this->newTable) {
    for (Cell & cell : subVector) {
      this->oldTable
        .at(cell.getCol())
        .at(cell.getRow())
        .setIsAlive(cell.getIsAlive());
    }
  }
}

void Board::randomFill() {
  for (int i = 0; i < this->cols; i++) {
    this->oldTable.push_back(std::vector<Cell>());
    this->newTable.push_back(std::vector<Cell>());
    for (int j = 0; j < this->rows; j++) {
      this->oldTable
        .at(i)
        .push_back(Cell(i, j, rand() % 2));
      
      this->newTable
        .at(i)
        .push_back(Cell(i, j, false));
    }
  }
}