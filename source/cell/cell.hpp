/**
 * @file cell.hpp
 * @author Rza Ismayilov (rzaismail82@gmail.com)
 * @author Taleh Taghiyev (taleh.taghiyev@ufaz.az)
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

class Cell {
private:
  /// column of cell
  int col;
  /// row of cell
  int row;
  /// state of cell
  bool isAlive;

public:
  /**
   * @brief Construct a new Cell object
   * 
   * @param row
   * @param col 
   * @param isAlive 
   */
  Cell(int row, int col, bool isAlive);

  /**
   * @brief Destroy the Cell object
   */
  ~Cell();

  /**
   * @brief Get the column object
   * 
   * @return int: the column of Cell 
   */
  int getCol();

  /**
   * @brief Get the row object
   * 
   * @return int: the row of Cell 
   */
  int getRow();

  /**
   * @brief Get the isAlive object
   * 
   * @return bool: true if the cell is alive
   * @return bool: false if the cell is dead
   */
  bool getIsAlive();

  /**
   * @brief Set the column object
   * 
   * @param col the new column of cell
   */
  void setCol(int col);

  /**
   * @brief Set the row object
   * 
   * @param row the new row of cell
   */
  void setRow(int row);

  /**
   * @brief Set the isAlive object
   * 
   * @param isAlive the new state of cell
   */
  void setIsAlive(bool isAlive);
};


