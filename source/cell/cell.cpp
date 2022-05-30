#include "cell.hpp"

Cell::Cell(int col, int row, bool isAlive) {
  this->col = col;
  this->row = row;
  this->isAlive = isAlive;
}

Cell::~Cell() {}

int Cell::getCol() {
  return  this->col;
}

int Cell::getRow() {
  return this->row;
}

bool Cell::getIsAlive() {
  return this->isAlive;
}

void Cell::setCol(int col) {
  this->col = col;
}

void Cell::setRow(int row) {
  this->row = row;
}

void Cell::setIsAlive(bool isAlive) {
  this->isAlive = isAlive;
}