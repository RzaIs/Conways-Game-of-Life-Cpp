#pragma once

class Cell {
private:
  int col, row;
  bool isAlive;

public:
  Cell(int col, int row, bool isAlive);
  ~Cell();

  int getCol();
  int getRow();
  bool getIsAlive();

  void setCol(int col);
  void setRow(int row);
  void setIsAlive(bool isAlive);
};


