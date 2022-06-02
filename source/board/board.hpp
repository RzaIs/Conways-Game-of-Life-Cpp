/**
 * @file board.hpp
 * @author Rza Ismayilov (rzaismail82@gmail.com)
 * @author Taleh Taghiyev (taleh.taghiyev@ufaz.az)
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <iostream>
#include <vector>

#include "cell.hpp"
#include "point.hpp"

class Board {
private:
  /// number of columns of tables
  int cols;
  
  /// number of rows of tables
  int rows;

  /// 2D vectors to store the previous state of table
  std::vector<std::vector<Cell>> oldTable;

  /// 2D vectors to store the future state of table
  std::vector<std::vector<Cell>> newTable;

  /**
   * @brief checks if the given col and row is in bounds of board
   * 
   * @param col the column to be checked
   * @param row the row to be checked
   * @return true if it is in bounds
   * @return false if it is out of bounds
   */
  bool cellBelong(int col, int row);

  /**
   * @brief calculate the state of cell for the next generation
   * 
   * @param cell the target cell
   * @return true if the next state is Alive
   * @return false if the next state is Dead
   */
  bool newCellState(Cell cell);

  /**
   * @brief copy the states of newTabel to oldTable
   */
  void copyTable();

  /**
   * @brief fill the cells with random states for the initial setup
   */
  void randomFill();

  /**
   * @brief counts the number of alive neighboring cells of the cell at position (col, row)
   * 
   * @param col the column of target cell
   * @param row the row of target cell
   * @return int: the number of alive neighboring cells
   */
  int countAliveNeighbors(int col, int row);

  /**
   * @brief Get the neighboring cells of the cell at position (col, row)
   * 
   * @param col the column of target cell
   * @param row the row of target cell
   * @return std::vector<Cell>: collection of neighboring cells
   */
  std::vector<Cell> getNeighbors(int col, int row);

public:
  /**
   * @brief Construct a new Board object
   * 
   * @param cols number of columns of tables
   * @param rows number of rows of tables
   */
  Board(int cols, int rows);

  /**
   * @brief Destroy the Board object
   */
  ~Board();

  /**
   * @brief generate the next state of oldTable to the newTable
   */
  void generateNext();

  /**
   * @brief Get the state of the cell at position (col, row)
   * 
   * @param col the column of target cell
   * @param row the row of target cell
   * @return true if the target cell is Alive
   * @return false if the target cell is Dead
   */
  bool getCellState(int col, int row);

};
