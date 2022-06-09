/**
 * @file ansi.hpp
 * @author Rza Ismayilov (rzaismail82@gmail.com)
 * @author Taleh Taghiyev (taleh.taghiyev@ufaz.az)
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>

/// COLORS

#define fgBlack "\e[0;30m"
#define fgRed "\e[0;31m"
#define fgGreen "\e[0;32m"
#define fgYellow "\e[0;33m"
#define fgBlue "\e[0;34m"
#define fgPurple "\e[0;35m"
#define fgCyan "\e[0;36m"
#define fgWhite "\e[0;37m"

#define bgBlack "\e[0;40m"
#define bgRed "\e[0;41m"
#define bgGreen "\e[0;42m"
#define bgYellow "\e[0;4m"
#define bgBlue "\e[0;44m"
#define bgPurple "\e[0;45m"
#define bgCyan "\e[0;46m"
#define bgWhite "\e[0;47m"

#define end "\033[0m"

class AnsiPrinter
{
public:
  /**
   * @brief Construct a new Ansi Printer object
   */
  AnsiPrinter();

  /**
   * @brief Destroy the Ansi Printer object
   */
  ~AnsiPrinter();

  /**
   * @brief prints a cell according to its state 
   * 
   * @param isAlive the state of cell
   */
  void print(bool isAlive);

  /**
   * @brief clear the console
   */
  void clear();

};
