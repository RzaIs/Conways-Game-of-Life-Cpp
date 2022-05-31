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

bool Board::newCellState(Cell cell) {
  int numberOfAliveNeighbors = this->countAliveNeighbors(
    cell.getCol(),
    cell.getRow()
  );

  if (cell.getIsAlive()) {
    if (numberOfAliveNeighbors == 3 || numberOfAliveNeighbors == 2)
      return true;
    else
      return false;
  } else {
    if (numberOfAliveNeighbors == 3)
      return true;
    else
      return false;
  }
}

void Board::generateNext() {

  for (std::vector<Cell> & subVector : this->oldTable) {
    for (Cell & cell : subVector) {
      this->newTable
        .at(cell.getCol())
        .at(cell.getRow())
        .setIsAlive(this->newCellState(cell));
    }
  }
  this->copyTable();
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

int Board::countAliveNeighbors(int col, int row) {
  int numberOfAliveCells = 0;

  std::vector<Cell> neighbors = this->getNeighbors(col, row);

  for (Cell & cell : neighbors) {
    if (cell.getIsAlive()) {
      numberOfAliveCells++;
    }
  }
  return numberOfAliveCells;
}

std::vector<Cell> Board::getNeighbors(int col, int row) {
  std::vector<Cell> neighbors;

  std::vector<Point> positions = {
    Point(col + 1, row + 1),
    Point(col + 1, row - 1),
    Point(col - 1, row + 1),
    Point(col - 1, row - 1),
    Point(col + 1, row),
    Point(col - 1, row),
    Point(col, row + 1),
    Point(col, row - 1)
  };

  for (Point & point : positions) {
    if (this->cellBelong(point.x, point.y)) {
      neighbors.push_back(
        this->oldTable
          .at(point.x)
          .at(point.y)
      );
    }
  }
  return neighbors;
}
