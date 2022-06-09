/**
 * @file game.hpp
 * @author Rza Ismayilov (rzaismail82@gmail.com)
 * @author Taleh Taghiyev (taleh.taghiyev@ufaz.az)
 * @version 0.1
 * @date 2022-06-03
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <unistd.h>

#include "board.hpp"
#include "ansi.hpp"

class Game {
private:
  /// number of columns of board
  int cols;

  /// number of rows of board
  int rows;

  /// ansi printer of game
  AnsiPrinter * ansiPrinter;

  /// board object of game
  Board * board;

  /**
   * @brief instructions for each game loop iteration
   */
  void cycle();

public:
  /**
   * @brief Construct a new Game object
   * 
   * @param cols the number of columns of board
   * @param rows the number of rows of board
   * @param scale the scaling coeff of renderer
   */
  Game(int cols, int rows);

  /**
   * @brief Destroy the Game object
   */
  ~Game();

  /**
   * @brief starting the game
   */
  void start();
};