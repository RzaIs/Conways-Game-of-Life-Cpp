#include "ansi.hpp"

AnsiPrinter::AnsiPrinter(int cols, int rows) {
  this->cols = cols;
  this->rows = rows;
}

AnsiPrinter::~AnsiPrinter() {}

void AnsiPrinter::print(bool isAlive) {
  if (isAlive) {
    std::cout << bgGreen << "  " << end;
  } else {
    std::cout << bgRed << "  " << end;
  }
}

void AnsiPrinter::clear() {

  std::cout << "\033[2J";
}
